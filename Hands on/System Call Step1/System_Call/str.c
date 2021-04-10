//Write your own system call which returns length of passed string

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define __NR_testcall 399

int main() {
int ret;

ret=syscall(__NR_testcall,"Hi! How r u?");
printf("%d\n",ret);
if(ret<0)
	perror("testcall");
return 0;
}
