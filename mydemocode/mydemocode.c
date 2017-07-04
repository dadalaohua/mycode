/*
   My demo code
*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>

#define DEVICE_NAME "My_demo_code"

static int mydemocode_open(struct inode *inode, struct file *filp)
{
    printk(KERN_NOTICE DEVICE_NAME" opened!\n");
    return 0;
}

static int mydemocode_release(struct inode *inode, struct file *filp)
{
    printk(KERN_NOTICE DEVICE_NAME" release!\n");
    return 0;
}

static int mydemocode_read(struct file *filp, char __user *buff,
        size_t count, loff_t *offp)
{
    printk(KERN_NOTICE DEVICE_NAME" read method!\n");
    return 0;
}

static int mydemocode_write(struct file *filp, const char __user *buff,
        size_t count, loff_t *offp)
{
    printk(KERN_NOTICE DEVICE_NAME" write method!\n");
    return 0;
}

static int mydemocode_ioctl(struct inode *inode, struct file *filp,
    unsigned int cmd, unsigned long arg)
{
    printk(KERN_NOTICE DEVICE_NAME" ioctl method!\n");
    return 0;
}

struct file_operations mydemocode_fops = {
    .owner      = THIS_MODULE,
    .read       = mydemocode_read,
    .write      = mydemocode_write,
    .open       = mydemocode_open,
    .release    = mydemocode_release,
    .ioctl      = mydemocode_ioctl
};

static struct miscdevice mydemocode_miscdev = {
	.minor  = MISC_DYNAMIC_MINOR,
	.name	= DEVICE_NAME,
	.fops	= &mydemocode_fops,
};

static int __init module_init_func(void)
{
    misc_register(&mydemocode_miscdev);
    printk(KERN_NOTICE"Hello,I'm ready!\n");
    return 0;
}

static int __exit module_exit_func(void)
{
    misc_deregister(&mydemocode_miscdev);
    printk("Bye!\n");
}

module_init(module_init_func);
module_exit(module_exit_func);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("hongjh");
MODULE_DESCRIPTION("my demo code");
