#define _GNU_SOURCE
#include<dlfcn.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>

int (*real_openat)(int fd1,const char* pathname1, int flags1)=NULL;
int open(const char *pathname,int flags){
	char cwd[128];
	int dir_fd;
	DIR *dir;
	printf("\n");
	if(getcwd(cwd,sizeof(cwd)) !=NULL){
		dir=opendir(cwd);
		dir_fd=dirfd(dir);
		write(STDOUT_FILENO,cwd,strlen(cwd));
		printf("\n");
		printf("From my open() function \n");
		printf("%d\n",dir_fd);
	}
	real_openat=dlsym(RTLD_NEXT,"openat");
	return real_openat(dir_fd,pathname,flags);
	
}
