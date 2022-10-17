#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
main()
{
	int x,y;
	char name[25];
	printf("enter directory name\n");
	scanf("%s",name);
	x=mkdir("name",0666);
	printf("%d\n",x);
	y=rmdir("name");
	printf("%d\n",y);
}
