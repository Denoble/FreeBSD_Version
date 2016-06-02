#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<dirent.h>
int main(){
	char cwd[128];
	int k;
	DIR *dir;
	if(getcwd(cwd,sizeof(cwd)) !=NULL){
		dir=opendir(cwd);
		k=dirfd(dir);
		write(STDOUT_FILENO,cwd,strlen(cwd));
		printf("%s","\n");
		printf("%d\n",k);
	}
}
