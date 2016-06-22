#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

char resolved_path[PATH_MAX + 1];
char cwd[1024];
void getabsolute_path(char* relative_path){
	realpath(relative_path,resolved_path);
	printf("\n%s\n",resolved_path);
}
void split_path_file(char** p, char** f, char *pf) {
    char *slash = pf, *next;
    while ((next = strpbrk(slash + 1, "\\/"))) slash = next;
    if (pf != slash) slash++;
    *p = strndup(pf, slash - pf);
    *f = strdup(slash);
}
int main()
{
        getabsolute_path(getcwd(cwd,sizeof(cwd)));
       
        return 0;
}