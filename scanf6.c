#include<stdio.h>
#include<string.h>
va_list type;
void myscanf(void *mk);
main()
{
	int p,q,r;
	char ptr[50];
	myscanf(type,ptr);
}
void myscanf(void *mk)
{
	int x,s;
	x=strcmp(*(char *)type,s);
	printf("%d\n",x);
	printf("%s\n",type);
}
