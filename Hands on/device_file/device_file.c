#include <linux/fs.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/init.h>

 

dev_t pdevid;
int ndevices=1;
struct device *pdev; //global
struct class *pclass; //global

 

static int __init psuedo_init(void)
{
    int ret;
    ret=alloc_chrdev_region(&pdevid, 0, ndevices, "pseudo_sample");
    if(ret) {
        printk("Pseudo: Failed to register driver\n");
        return -EINVAL;
    }
    
    int i=0;
    pclass = class_create(THIS_MODULE, "pseudo_class");
    //alloc_chrdev_region, cdev_init, cdev_add
    pdev = device_create(pclass, NULL, pdevid, NULL, "psample%d",i);
    
    
    printk("Successfully registered,major=%d,minor=%d\n",MAJOR(pdevid), MINOR(pdevid));
    printk("Pseudo Driver Sample..welcome\n");
    return 0;
}
static void __exit psuedo_exit(void) {
    unregister_chrdev_region(pdevid, ndevices);
    printk("Pseudo Driver Sample..Bye\n");
}
module_init(psuedo_init);
module_exit(psuedo_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Akshansh Mishra");
MODULE_DESCRIPTION("Parameter demo Module");
