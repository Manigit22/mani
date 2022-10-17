#include<stdio.h>
#include<pthread.h>
void *pthread_small(char *);
void *large(char *);
void main()
{
	int *ptr;
	pthread_t t1,t2;
	int x;
	char str[25];
	printf("enter the string\n");
	scanf("%s",str);
	pthread_create(&t1,NULL,pthread_small,&str);
	pthread_create(&t2,NULL,large,str);
	pthread_join(t1,&ptr);
	pthread_join(t2,NULL);
}
void *pthread_small(char *ptr)
{
	int i;
	for(i=0;ptr[i]!='\0';i++)
	{
		if(ptr[i]>=97 && ptr[i]<=122)	
			printf("small letter: %c\n",ptr[i]);
		
	}
}
void *large(char *ptr)
{
        int i;
        for(i=0;ptr[i]!='\0';i++)
        {
                if(ptr[i]>=65 && ptr[i]<=90)
                        printf("CAPITAL LETTER: %c\n",ptr[i]);

        }
}
