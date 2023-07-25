//Hello world programme from Oreilly text book 

#include<linux/init.h>
#include<linux/module.h>
#include<linux/sched.h>
#include<linux/moduleparam.h>
#include<linux/stat.h>
#include<linux/kernel.h>

// this is part of special kernel macros 
// Either the module is free or licensed 
// without this declaration kernel complains
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("SRINIVAS REPAKA");
MODULE_DESCRIPTION("executing the programme based on oreilly text book");

//static is not mandatory because it is used to make the same function is not called somewhere else
//static int __init hello_world(void) in this __init is not mandatory 
static int hello_world(void){
	// printk is similar to the printf in user space
	// since kernel requires its own function because it runs on itself without use of c library
	// KERN_ALERT is priority of message
	printk(KERN_ALERT "Hello, world\n");
	static char *whom = "srinivas"; // Linux everything is string and declaration will be in this format
	static int number = 210527;// Linux internal numbers are in this format
	
	//module_param(number, int , S_IRUGO);
	//module_param(whom, charp, S_IRUGO);
	//This is current function which give the operation and pid of the process.
	//eg:- The process is "insmod" (pid 251113)
	printk(KERN_INFO "The code is written by %s empid %i\n",whom, number);
	printk(KERN_INFO "The process is \"%s\" (pid %i)\n",current->comm, current->pid);
	return 0;
}


//static void __exit hello_exit(void) in this __exit is not mandatory 
static void __exit hello_exit(void){
	printk(KERN_INFO "The process is \"%s\" (pid %i)\n",current->comm, current->pid);
	printk(KERN_ALERT"Good bye\n");
}


// module_init will be called once the module is loaded (hello_world) 
// this is part of special kernel macros 
module_init(hello_world);

// module_exit will be called once the remove module is happened (hello_exit)
// this is part of special kernel macros
module_exit(hello_exit);
