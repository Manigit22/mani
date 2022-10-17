#include<stdio.h>
#include<unistd.h>
main()
{
	printf("before changing process image\n");
	execl("/bin/ps","ps",NULL);//ps,ls,pwd,.....
	printf("after changing process image\n");
}
