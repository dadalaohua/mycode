/*
   My reverse code
*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>	/* copy_{to,from}_user() */
#include <linux/slab.h>		/* kmalloc() kzalloc() function */

#define DEVICE_NAME "My_reverse"

static unsigned char data[256] = {0};
static unsigned long buffer_size = 2048;
module_param(buffer_size, ulong, (S_IRUGO));
MODULE_PARM_DESC(buffer_size, "buffer size");

struct buffer{
    char *data;
    unsigned long size;
};

static struct buffer *buffer_alloc(unsigned long size)
{
    struct buffer *buf = NULL;
    
    buf = kzalloc(sizeof(*buf), GFP_KERNEL);
    
    buf->data = kzalloc(size, GFP_KERNEL);
    
    buf->size = size;
    
 out:
    return buf;
    
 out_free:
    kfree(buf);
    return NULL;
}

static void buffer_free(struct buffer *buf)
{
    kfree(buf->data);
    kfree(buf);
}

static int myreverse_open(struct inode *inode, struct file *filp)
{
    printk(KERN_NOTICE DEVICE_NAME" opened!\n");
   
    return 0;
}

static int myreverse_release(struct inode *inode, struct file *filp)
{
    printk(KERN_NOTICE DEVICE_NAME" release!\n");
   
    return 0;
}

static int myreverse_read(struct file *filp, char __user *buff,
        size_t count, loff_t *offp)
{  
    if(count > 256){
        printk(KERN_WARNING DEVICE_NAME" count > 256!\n");
        count = 256;
    }
    
    if(copy_to_user((void *)buff, data, count)){
        printk(KERN_ERR DEVICE_NAME" copy_to_user err!\n");
    }
    
    return count;
}

static int myreverse_write(struct file *filp, const char __user *buff,
        size_t count, loff_t *offp)
{   
    if(count > 256){
        printk(KERN_WARNING DEVICE_NAME" count > 256!\n");
        count = 256;
    }
    
    if(copy_from_user(&data, buff, count)){
        printk(KERN_ERR DEVICE_NAME" copy_to_user err!\n");
    }
    
    return count;
}

static int myreverse_ioctl(struct inode *inode, struct file *filp,
    unsigned int cmd, unsigned long arg)
{
    printk(KERN_NOTICE DEVICE_NAME" ioctl method!\n");
    
    return 0;
}

struct file_operations myreverse_fops = {
    .owner      = THIS_MODULE,
    .read       = myreverse_read,
    .write      = myreverse_write,
    .open       = myreverse_open,
    .release    = myreverse_release,
    .ioctl      = myreverse_ioctl
};

static struct miscdevice myreverse_miscdev = {
	.minor  = MISC_DYNAMIC_MINOR,
	.name	= DEVICE_NAME,
	.fops	= &myreverse_fops,
};

static int __init module_init_func(void)
{
    misc_register(&myreverse_miscdev);
    printk(KERN_NOTICE"Hello,I'm ready!\n");
    return 0;
}

static int __exit module_exit_func(void)
{
    misc_deregister(&myreverse_miscdev);
    printk("Bye!\n");
}

module_init(module_init_func);
module_exit(module_exit_func);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("hongjh");
MODULE_DESCRIPTION("my reverse code");
