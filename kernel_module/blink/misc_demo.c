#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>

/* 所有混杂设备的主设备号都为10
 * 混杂类目录 /sys/class/misc
 * 设备目录 /dev/miscdevice.name
 */

struct file_operations demo_dev_fops = 
{
	.owner = THIS_MODULE,
};

static struct miscdevice demo_dev = 
{
	.minor = MISC_DYNAMIC_MINOR,
	.name = "misc_demo",
	.fops = &demo_dev_fops,
};

static int __init demo_dev_init(void)
{
	misc_register(&demo_dev);
	return 0;
}

static void __exit demo_dev_exit(void)
{
	misc_deregister(&demo_dev);
}

module_init(demo_dev_init);
module_exit(demo_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("concelfy@foxmail.com");
MODULE_DESCRIPTION("misc device driver test");
