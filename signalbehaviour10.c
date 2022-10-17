#include<stdio.h>
#include<signal.h>
main()
{
	int x;
	x=signal(2,SIG_IGN);
	printf("%d\n",x);
	while(1)
	{
		printf("1");
	}
}
