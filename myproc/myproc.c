/*
   My reverse code
*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>	/* copy_{to,from}_user() */
#include <linux/proc_fs.h>	/* proc */

#define DEVICE_NAME "My_proc"

static unsigned char data[256] = {0};

static char myproc_data[256] = {0};
struct proc_dir_entry *example_dir, *hello_file;

static int myproc_proc_read(char *page, char **start, off_t off,
        int count, int *eof, void *data)
{   
    int len;
    
    len = sprintf(page, myproc_data);
    
    return len;
}

static int myproc_proc_write(struct file *file, const __user *buffer,
        unsigned long count, void *data)
{   
    if(count > 256){
        printk(KERN_WARNING DEVICE_NAME" count > 256!\n");
        count = 256;
    }
    
    if(copy_from_user(myproc_data, buffer, count)){
        printk(KERN_ERR DEVICE_NAME" copy_to_user err!\n");
    }
    myproc_data[count] = '\0';
    
    return count;
}

static int myproc_proc_init(void)
{    
    example_dir = proc_mkdir("mycode", NULL);
    hello_file  = create_proc_entry("my_proc", 0666, example_dir);
    
    hello_file->read_proc  = myproc_proc_read;
    hello_file->write_proc = myproc_proc_write;
    
    return 0;
}

static int myproc_proc_exit(void)
{
    remove_proc_entry("my_proc", example_dir);
    remove_proc_entry("mycode", NULL);
 
    return 0;
}

static int myproc_open(struct inode *inode, struct file *filp)
{   
    try_module_get(THIS_MODULE);
    
    return 0;
}

static int myproc_release(struct inode *inode, struct file *filp)
{  
    module_put(THIS_MODULE);
    
    return 0;
}

static int myproc_read(struct file *filp, char __user *buff,
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

static int myproc_write(struct file *filp, const char __user *buff,
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

static int myproc_ioctl(struct inode *inode, struct file *filp,
    unsigned int cmd, unsigned long arg)
{
    printk(KERN_NOTICE DEVICE_NAME" ioctl method!\n");
    
    return 0;
}

struct file_operations myproc_fops = {
    .owner      = THIS_MODULE,
    .read       = myproc_read,
    .write      = myproc_write,
    .open       = myproc_open,
    .release    = myproc_release,
    .ioctl      = myproc_ioctl
};

static struct miscdevice myproc_miscdev = {
	.minor  = MISC_DYNAMIC_MINOR,
	.name	= DEVICE_NAME,
	.fops	= &myproc_fops,
};

static int __init module_init_func(void)
{
    misc_register(&myproc_miscdev);
    myproc_proc_init();
    printk(KERN_NOTICE"Hello,I'm ready!\n");
    return 0;
}

static int __exit module_exit_func(void)
{
    myproc_proc_exit();
    misc_deregister(&myproc_miscdev);
    printk("Bye!\n");
}

module_init(module_init_func);
module_exit(module_exit_func);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("hongjh");
MODULE_DESCRIPTION("my demo code");
