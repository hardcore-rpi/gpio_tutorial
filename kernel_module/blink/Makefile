# Makefile2.6

ifneq ($(KERNELRELEASE),)
	# kbuild syntax. dependency relationshsip of files and target modules are listed here.
	mymodule-objs := misc_demo.o
	obj-m := misc_demo.o
else
	PWD  := $(shell pwd)
	KDIR := /home/concefly/kernel/linux-3.10.25

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules  ARCH=arm  CROSS_COMPILE=arm-linux-gnueabi-
clean:
	rm -rf .*.cmd *.o *.mod.c *.ko .tmp_versions

endif
