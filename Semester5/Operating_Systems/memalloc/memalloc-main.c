/* General headers */
#include <linux/kthread.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kallsyms.h>
#include <linux/skbuff.h>
#include <linux/freezer.h>
#include <linux/mutex.h>
#include <linux/cdev.h>
#include <linux/mm.h>
#include <linux/sched/mm.h>
#include <linux/highmem.h>
#include <asm/pgtable.h>
#include <asm/tlbflush.h>
#include <linux/vmalloc.h>
#include <asm/pgalloc.h>

/* File IO-related headers */
#include <linux/fs.h>
#include <linux/bio.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>
#include <linux/blkdev.h>

/* Sleep and timer headers */
#include <linux/hrtimer.h>
#include <linux/delay.h>
#include <linux/sched.h>
#include <linux/sched/types.h>
#include <linux/pci.h>

#include "../common.h"
#include "memalloc-common.h"

/* Simple licensing stuff */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("student");
MODULE_DESCRIPTION("Project 4, CSE 330 Fall 2025");
MODULE_VERSION("0.01");

/* Calls which start and stop the ioctl teardown */
bool memalloc_ioctl_init(void);
void memalloc_ioctl_teardown(void);

/* Project 2 Solution Variable/Struct Declarations */
#define MAX_PAGES           4096
#define MAX_ALLOCATIONS     100

#if defined(CONFIG_X86_64)
    #define PAGE_PERMS_RW		PAGE_SHARED
    #define PAGE_PERMS_R		PAGE_READONLY
#else
    #define PAGE_PERMS_RW		__pgprot(_PAGE_DEFAULT | PTE_USER | PTE_NG | PTE_PXN | PTE_UXN | PTE_WRITE)
    #define PAGE_PERMS_R		__pgprot(_PAGE_DEFAULT | PTE_USER | PTE_NG | PTE_PXN | PTE_UXN | PTE_RDONLY)
#endif

struct alloc_info           alloc_req;
struct free_info            free_req;

/* Structures used to create a virtual device */
static dev_t                dev = 0;
static struct class*        virtdev_class;
static struct cdev          virtdev_cdev;

static int total_pages_allocated = 0;
static int total_allocations = 0;

static long memalloc_ioctl(struct file *f, unsigned int cmd, unsigned long arg);

/* Required file ops. */
static struct file_operations fops = 
{
    .owner          = THIS_MODULE,
    .unlocked_ioctl = memalloc_ioctl,
};


/* Init and Exit functions */
static int __init memalloc_module_init(void) {
    printk("Hello from the memalloc module!\n");
    /* Allocate a character device. */
    if (alloc_chrdev_region(&dev, 0, 1, "virtdev") < 0) {
        printk("error: couldn't allocate chardev region.\n");
        return -1;
    }
    printk("[*] Allocated chardev.\n");

    /* Initialize the chardev with my fops. */
    cdev_init(&virtdev_cdev, &fops);

    if (cdev_add(&virtdev_cdev, dev, 1) < 0) {
        printk("[x] Couldn't add virtdev cdev.\n");
        goto cdevfailed;
    }
    printk("[*] Allocated cdev.\n");

    if ((virtdev_class = class_create("memalloc_class")) == NULL) {
        printk("[X] couldn't create class.\n");
        goto cdevfailed;
    }
    printk("[*] Allocated class.\n");

    if ((device_create(virtdev_class, NULL, dev, NULL, "memalloc")) == NULL) {
        printk("[X] couldn't create device.\n");
        goto classfailed;
    }
    printk("[*] Virtual device added.\n");

    return 0;

    classfailed:
        class_destroy(virtdev_class);
    cdevfailed:
        unregister_chrdev_region(dev, 1);

    return -1;
}

static void __exit memalloc_module_exit(void) {
    /* Teardown IOCTL */
    printk("Goodbye from the memalloc module!\n");
    if (virtdev_class) {
        device_destroy(virtdev_class, dev);
        class_destroy(virtdev_class);
    }
    cdev_del(&virtdev_cdev);
    unregister_chrdev_region(dev,1);
    printk("[*] Virtual device removed.\n");
}

/* IOCTL handler for vmod. */
static long memalloc_ioctl(struct file *f, unsigned int cmd, unsigned long arg) {
    switch (cmd)
    {
    case ALLOCATE:    	
        if (copy_from_user((void *)&alloc_req, (void *)arg, sizeof(struct alloc_info))) {
            printk("Error: User didn't send proper alloc_info.\n");
            return -1;
        }
        if ((total_pages_allocated + alloc_req.num_pages) > MAX_PAGES) {
            printk("Error: Exceeded max allowed pages.\n");
            return -2;
        }
        if (total_allocations >= MAX_ALLOCATIONS) {
            printk("Error: Exceeded max allowed allocations.\n");
            return -3;
        }

        printk("IOCTL: alloc(%lx, %d, %d)\n", alloc_req.vaddr, alloc_req.num_pages, alloc_req.write);

        for (int i = 0; i < alloc_req.num_pages; i++) {
            unsigned long vaddr = alloc_req.vaddr + i * PAGE_SIZE;

            // Check if the address is valid and mapped
            pgd_t *pgd = pgd_offset(current->mm, vaddr);
            if (pgd_none(*pgd)) {
                printk("Error: PGD should always be mapped.\n");
                return -EFAULT;
            }

            p4d_t *p4d = p4d_offset(pgd, vaddr);
            if (p4d_none(*p4d)) {
                memalloc_pud_alloc(p4d, vaddr);
                p4d = p4d_offset(pgd, vaddr);
            }

            pud_t *pud = pud_offset(p4d, vaddr);
            if (pud_none(*pud)) {
                memalloc_pmd_alloc(pud, vaddr);
                pud = pud_offset(p4d, vaddr);
            }

            pmd_t *pmd = pmd_offset(pud, vaddr);
            if (pmd_none(*pmd)) {
                memalloc_pte_alloc(pmd, vaddr);
                pmd = pmd_offset(pud, vaddr);
            }

            pte_t *pte = pte_offset_kernel(pmd, vaddr);
            if (!pte_none(*pte)) {
                printk("Error: PTE already present at %lx. Cannot overwrite.\n", vaddr);
                return -EEXIST;
            }

            gfp_t gfp = GFP_KERNEL_ACCOUNT;
            void *kpage = (void *)get_zeroed_page(gfp);
            if (!kpage) {
                printk("Error: Failed to allocate memory page.\n");
                return -ENOMEM;
            }

            unsigned long paddr = __pa(kpage);
            pgprot_t perms = alloc_req.write ? PAGE_PERMS_RW : PAGE_PERMS_R;

            set_pte_at(current->mm, vaddr, pte, pfn_pte((paddr >> PAGE_SHIFT), perms));
        }

        total_pages_allocated += alloc_req.num_pages;
        total_allocations += 1;

        break;

    case FREE:   
        if (copy_from_user((void *)&free_req, (void *)arg, sizeof(struct free_info))) {
            printk("Error: User didn't send proper free_info.\n");
            return -1;
        }

        printk("IOCTL: free(%lx)\n", free_req.vaddr);

        unsigned long vaddr = free_req.vaddr;

        pgd_t *pgd = pgd_offset(current->mm, vaddr);
        if (pgd_none(*pgd)) {
            printk("Error: PGD not present.\n");
            return -EFAULT;
        }

        p4d_t *p4d = p4d_offset(pgd, vaddr);
        if (p4d_none(*p4d)) {
            printk("Error: P4D not present.\n");
            return -EFAULT;
        }

        pud_t *pud = pud_offset(p4d, vaddr);
        if (pud_none(*pud)) {
            printk("Error: PUD not present.\n");
            return -EFAULT;
        }

        pmd_t *pmd = pmd_offset(pud, vaddr);
        if (pmd_none(*pmd)) {
            printk("Error: PMD not present.\n");
            return -EFAULT;
        }

        pte_t *pte = pte_offset_kernel(pmd, vaddr);
        if (pte_none(*pte)) {
            printk("Warning: PTE is already empty at %lx. Nothing to free.\n", vaddr);
            return -EFAULT;
        }

        // Get the physical page from PTE
        struct page *page = pte_page(*pte);
        if (!page) {
            printk("Error: Failed to get page from PTE.\n");
            return -EFAULT;
        }

        // Free the page
        __free_page(page);

        // Clear the PTE and flush TLB
        pte_clear(current->mm, vaddr, pte);

        break;  

    default:
        printk("Error: incorrect IOCTL command.\n");
        return -1;
    }
    return 0;
}


/* Initialize the module for IOCTL commands */
bool memalloc_ioctl_init(void) {
    return false;
}

void memalloc_ioctl_teardown(void) {
    /* Destroy the classes too (IOCTL-specific). */
}

module_init(memalloc_module_init);
module_exit(memalloc_module_exit);