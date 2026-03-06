obj-m += kmod.o
kmod-y += kmod-main.o kmod-ioctl.o

all:
	make -C /usr/src/linux M=$(PWD) modules

clean:
	make -C /usr/src/linux M=$(PWD) clean

install:
	insmod kmod.ko
remove: 
	rmmod kmod
