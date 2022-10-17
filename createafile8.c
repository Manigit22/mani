#include<stdio.h>
main()
{
	FILE *x;
	char name[25];
	printf("enter the file name\n");
	scanf("%s",name);
	x=fopen(name,"w");
	printf("%d\n",x);
}
