#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>

/* 所有混杂设备的主设备号都为10
 * 混杂类目录 /sys/class/misc
 * 设备目录 /dev/miscdevice.name
 */

int led_dev_open(struct inode * ip, struct file * fp)
{
	;
}

ssize_t led_dev_write(struct file * fp, const char __user * up, size_t size, loff_t * ltp)
{
	;
}

ssize_t led_dev_read(struct file * fp, char __user * up, size_t size, loff_t * ltp)
{
	;
}

struct file_operations led_dev_fops =
{
	.owner = THIS_MODULE,
	.open = led_dev_open,
	.close = led_dev_close,
	.write = led_dev_write,
	.read = led_dev_read,
};

static struct miscdevice led_dev =
{
	.minor = MISC_DYNAMIC_MINOR,
	.name = "blink_led",
	.fops = &led_dev_fops,
};

static int __init led_dev_init(void)
{
	misc_register(&led_dev);
	return 0;
}

static void __exit led_dev_exit(void)
{
	misc_deregister(&led_dev);
}

module_init(led_dev_init);
module_exit(led_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("concelfy@foxmail.com");
MODULE_DESCRIPTION("let's blink a LED");
