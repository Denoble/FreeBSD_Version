#include<stdio.h>
#include<fcntl.h>
#include"prehead.h"
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>
int main(){
	
	int fd;
	fd =open("test.txt",O_RDONLY);
	if(fd<0){
		printf("open() returned NULL\n");
		return 1;
	}
	printf("open() succeedded\n");
	return 0;
}
