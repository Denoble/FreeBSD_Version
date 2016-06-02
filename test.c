#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	write(STDOUT_FILENO,"Hello,kernel!\n",15);
	printf("Hello,world!\n");
}
