# Makefile2.6

ifneq ($(KERNELRELEASE),)
	# kbuild syntax. dependency relationshsip of files and target modules are listed here.
	mymodule-objs := blink_led_driver.o
	obj-m := blink_led_driver.o
else
	PWD  := $(shell pwd)
	KDIR := /home/concefly/project/git/rpi_linux

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules  ARCH=arm  CROSS_COMPILE=arm-linux-gnueabi-
clean:
	rm -rf .*.cmd *.o *.mod.c *.ko .tmp_versions

endif
