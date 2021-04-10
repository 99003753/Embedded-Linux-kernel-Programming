#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
int __init init_module(void)
 {
  printk("Hello World \n");
  return 0;
 }
void __exit cleanup_module(void)
 {
  printk("HI,from LTTS! \n");
 }
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Akshansh Mishra");
MODULE_DESCRIPTION("A SIMPLE MODULE");

