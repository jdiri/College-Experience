#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/semaphore.h>
#include <linux/slab.h>
#include <linux/delay.h>

static int prod = 0, cons = 0, size = 0;
module_param(prod, int, 0644);
module_param(cons, int, 0644);
module_param(size, int, 0644);

static struct semaphore empty;
static struct semaphore full;

static struct task_struct **producers;
static struct task_struct **consumers;

// Producer thread function
static int producer_thread(void *arg) {
    int id = (long)arg + 1;  // Producer ID
    while (!kthread_should_stop()) {
        down_interruptible(&empty);
        printk(KERN_INFO "An item has been produced by Producer-%d\n", id);
        up(&full);
        msleep(100);  // Simulate some delay
    }
    return 0;
}

// Consumer thread function
static int consumer_thread(void *arg) {
    int id = (long)arg + 1;  // Consumer ID
    while (!kthread_should_stop()) {
        down_interruptible(&full);
        printk(KERN_INFO "An item has been consumed by Consumer-%d\n", id);
        up(&empty);
        msleep(100);  // Simulate some delay
    }
    return 0;
}

// Module initialization
static int __init producer_consumer_init(void) {
    int i;

    printk(KERN_INFO "Producer-Consumer Module Loaded\n");

    // Initialize semaphores
    sema_init(&empty, size);
    sema_init(&full, 0);

    // Allocate memory for threads
    producers = kmalloc_array(prod, sizeof(*producers), GFP_KERNEL);
    consumers = kmalloc_array(cons, sizeof(*consumers), GFP_KERNEL);

    if (!producers || !consumers) {
        printk(KERN_ERR "Failed to allocate memory for threads\n");
        return -ENOMEM;
    }

    // Create producer threads
    for (i = 0; i < prod; i++) {
        producers[i] = kthread_run(producer_thread, (void *)(long)i, "Producer-%d", i + 1);
        if (IS_ERR(producers[i])) {
            printk(KERN_ERR "Failed to create Producer-%d\n", i + 1);
        }
    }

    // Create consumer threads
    for (i = 0; i < cons; i++) {
        consumers[i] = kthread_run(consumer_thread, (void *)(long)i, "Consumer-%d", i + 1);
        if (IS_ERR(consumers[i])) {
            printk(KERN_ERR "Failed to create Consumer-%d\n", i + 1);
        }
    }

    return 0;
}

// Cleanup function to stop threads
static void c_p_module(void) {
    int i;
    for (i = 0; i < prod; i++) {
        if (producers[i])
            kthread_stop(producers[i]);
    }
    for (i = 0; i < cons; i++) {
        if (consumers[i])
            kthread_stop(consumers[i]);
    }
    kfree(producers);
    kfree(consumers);
}

// Module exit function
static void __exit producer_consumer_exit(void) {
    c_p_module();
    printk(KERN_INFO "Producer-Consumer Module Unloaded\n");
}

module_init(producer_consumer_init);
module_exit(producer_consumer_exit);
MODULE_LICENSE("GPL");

