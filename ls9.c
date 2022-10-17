#include<stdio.h>
#include<dirent.h>
main()
{
	DIR *d;
	struct dirent *x;
	d=opendir(".");
	while((x=readdir(d))!=NULL)
		printf("%s\t",x->d_name);
	closedir(d);
	printf("\n");
}
