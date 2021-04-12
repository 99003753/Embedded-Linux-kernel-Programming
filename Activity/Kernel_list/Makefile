  
obj-m += ioctl_listfn.o
KSRC=/home/user/KSRC
all:
	make -C ${KSRC} M=${PWD} modules ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-
clean:
	make -C ${KSRC} M=${PWD} modules ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- 
build:
	arm-linux-gnueabi-gcc userspace.c -o userspace..out 
