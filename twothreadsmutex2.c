#include<stdio.h>
#include<pthread.h>
void *thread1(void *mk);
void *thread2(void *mk);
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
int p=0;
main()
{
	int **ptr;
	int x;
	pthread_t t1,t2;
	printf("enter the value\n");
	scanf("%d",&x);
	pthread_create(&t1,NULL,thread1,&x);
	pthread_create(&t2,NULL,thread2,&x);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_mutex_lock(&mutex1);
}
void *thread1(void *mk)
{
	int x,i;
	x=*(int *)mk;
	for(i=0;i<x;i++)
	{
		pthread_mutex_lock(&mutex);
		//printf("thread1: %d\n",i);
		p++;
		printf("thread1: %d\n",p);
		pthread_mutex_unlock(&mutex1);
	}
}
void *thread2(void *mk)
{       
        int x,i;
        x=*(int *)mk;
	for(i=0;i<x;i++)
	{
		pthread_mutex_lock(&mutex1);
                //printf("thread2: %d\n",i);
                p++;
                printf("thread2: %d\n",p);
		pthread_mutex_unlock(&mutex);
	}
}       

