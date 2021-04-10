obj-m += register.o
KSRC = /lib/modules/$(shell uname -r)/build


all:
	make -C /home/user/KSRC M=${PWD} modules ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-
