#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/kthread.h>
#include <linux/delay.h>

static struct task_struct *task1;
static struct task_struct *task2;
int i=0;
//task1=kthread_run(thread_one, NULL, "thread_A");
static int thread_one(void *pargs){

while(!kthread_should_stop())
{
	printk("Thread A--%d\n",i++);
	msleep(1000); //ssleep, usleep
}
do_exit(0);
return 0;
}

//kthread_create + wake_up_process
//task2=kthread_run(thread_two, NULL, "thread_B");

static int thread_two(void *pargs){

while(!kthread_should_stop())
{
	printk("Thread B --%d\n",i++);
	msleep(1000); //ssleep, usleep
}
do_exit(0);
return 0;
}

static int __init psuedo_init(void)
{
	task1=kthread_run(thread_one, NULL, "thread_A");
	task2=kthread_run(thread_two, NULL, "thread_B");
	return 0;
}
static void __exit psuedo_exit(void) {
	//tdemo_exit:-
	if(task1)
		kthread_stop(task1);
	if(task2)
		kthread_stop(task2);
}
module_init(psuedo_init);
module_exit(psuedo_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Akshansh");
MODULE_DESCRIPTION("Parameter demo Module");
