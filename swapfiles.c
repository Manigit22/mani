#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
main(int argc,char *argv[])
{
	int fd1,fd2,x,y;
	char buf1[1000],buf2[1000];
	printf("Before swapping the files\n");
	fd1=open(argv[1],O_RDONLY);
	printf("fd1: %d\n",fd1);
	if(fd1<0)
	{
		printf("fd1 open fails in read mode\n");
		exit(0);
	}
	x=read(fd1,buf1,1000);
	if(x<=0)
	{
		printf("file1 read fails\n");
		exit(1);
	}
	buf1[x]='\0';
	printf("file 1 data is %s\n",buf1);
	fd2=open(argv[2],O_RDONLY);
	printf("fd2: %d\n",fd2);
	if(fd2<0)
	{
		printf("fd2 open fails in read mode\n");
		exit(2);
	}
	y=read(fd2,buf2,1000);
	if(y<=0)
	{
		printf("file 2 read fails\n");
		exit(3);
	}
	buf2[y]='\0';
	printf("file 2 data is %s\n",buf2);
	fd1=open(argv[1],O_WRONLY);
	if(fd1<0)
	{
		printf("fd1 open fails in write mode\n");
		exit(6);
	}
	x=write(fd1,buf2,strlen(buf2));
	if(x<0)
	{
		printf("file 1 write fails\n");
		exit(4);
	}
	printf("file 1 data is %s\n",buf2);
	fd2=open(argv[2],O_WRONLY);
	if(fd2<0)
	{
		printf("fd2 open fails in write mode\n");
		exit(7);
	}
	y=write(fd2,buf1,1000);
	if(y<0)
	{
		printf("file 2 write fails\n");
		exit(5);
	}
	printf("file 2 data is %s\n",buf1);
}
