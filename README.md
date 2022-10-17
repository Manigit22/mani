1.#Change the process image


##SYNOPSIS
	#include <unistd.h>
        int execl(const char *path, const char *arg, ...,NULL);


##DESCRIPTION
	If you want to replace the existing process with new process.Then, exec family of calls to be used.
	execl : The first argument should point the path name associated with the file being executed.The second argument represents the argument list available to the program. The third argument represents the variadic functions,this pointer must be NULL.


#RETURN VALUE
	On success, it will not return any value because of the process is replaced with any process.On failure, it will return -1.



2.#Threads using mutex

##SYNOPSIS
	#include<stdio.h>
	#include<pthread.h>
	int pthread_create(pthread_t *restrict thread,const pthread_attr_t *restrict attr,void *(*start_routine)(void *),void *restrict arg);
	int pthread_join(pthread_t thread, void **retval);
	int pthread_mutex_lock(pthread_mutex_t *mutex);
       int pthread_mutex_unlock(pthread_mutex_t *mutex);
	
##DESCRIPTION
	The pthread_create() function starts a new thread in the calling process.  The new thread starts execution by invoking new thread function.
	It creates a thread and acts as a blocking call.
	The mutex object referenced by mutex shall be locked by a call to pthread_mutex_lock() that returns zero.
	The mutex object referenced by mutex shall be unlocked by a call to pthread_mutex_unlock(). 
##RETURN VALUE
	On success, pthread_create() returns 0; on error, it returns an error number, and the contents of *thread are undefined.
	
3.#Own kill command

##SYNOPSIS
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<signal.h>
	int kill(pid_t pid, int sig);
	
##DESCRIPTION
	The kill() system call can be used to send any signal to any process.
	
##RETURN VALUE
	On success (at least one signal was sent), zero is returned.  On error, -1 is returned.
       
4.#Small and capital characters in thread

##SYNOPSIS
	#include<stdio.h>
	#include<pthread.h>
	int pthread_create(pthread_t *restrict thread,const pthread_attr_t *restrict attr,void *(*start_routine)(void *),void *restrict arg);
	int pthread_join(pthread_t thread, void **retval);
	
##DESCRIPTION
	The pthread_create() function starts a new thread in the calling process.  The new thread starts execution by invoking new thread function.
	It creates a thread and acts as a blocking call.
	
##RETURN VALUE
	On success, pthread_create() returns 0; on error, it returns an error number, and the contents of *thread are undefined.

6.#Create a directory,remove a directory

##SYNOPSIS
	#include<fcntl.h>
	#include<unistd.h>
	#include<sys/stat.h>
	int mkdir(const char *pathname, mode_t mode);
	int rmdir(const char *pathname);

##DESCRIPTION
	mkdir is used to create a directory.
	rmdir is used to delete a directory.

##RETURN VALUE
	On success it will return 0,on failure -1 

       
8.#Create a file without using create system call

##SYNOPSIS
	#include<fcntl.h> // for open the file
	#include<unistd.h> //for close the file
	int open(const char *path,int oflags,mode_t mode);
	int close(int fd);

##DESCRIPTION
	The open() function with three arguments is used to create and open the file. Give the name for creating the file that represents the first argument.The second argument represents the predefined macros i.e O_CREAT,O_RDONLY,O_WRONLY,O_RDWR etc. The third argument represents the permissions.

##RETURN VALUE
	open() : On success it will return open file fd, On failure it will return -1.
	close() : On success it will return 0, On failure it will return -1. 

9.#ls command

##SYNOPSIS
	#include<stdio.h>
	#include<dirent.h>
	DIR *opendir(const char *name);


##DESCRIPTION
	opendir opens the directory corresponding to directory name.
	struct old_linux_dirent {
               unsigned long d_ino;     /* inode number */
               unsigned long d_offset;  /* offset to this old_linux_dirent */
               unsigned short d_namlen; /* length of this d_name */
               char  d_name[1];         /* filename (null-terminated) */
           }

##RETURN VALUE
	The opendir() function return a pointer to the directory stream.  On error, NULL is returned.
	The readdir() onsuccess 1 is returned,on error -1 is returned.

10.#Change the signal behaviour

##SYNOPSIS
	#include<signal.h>
	int sigaction(int signal no,const struct sigaction *restrict set/act,struct sigaction *restrict *oldact);


##DESCRIPTION
	The  sigaction()  system  call  is used to change the behaviour taken by process of a specified signal. It have some pre-defined structure like
          struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };
First argument is signal num, specifies the signal and can be any valid signal except SIGSTOP and SIGKILL. Second argument is the sigaction structure variable name. Third argument is the oldact that is previous action.


##RETURN VALUE
	On success it will return 0, On failure it will return -1.



11.#Swap the content of two files

##SYNOPSIS
	#include<fcntl.h> // for open the file
	#include<unistd.h> //for read the data in file,write the data in file,close the file
	int open(const char *path,int oflags);
	ssize_t read(int fd,void *buf,size_t nbytes);
	ssize_t write(int fd,const void *buf,size_t count);
	int close(int fd);

##DESCRIPTION
	To swap the content of two existing files by using these system calls like open(),read(),write(),close(). First open the file-1 and read the content and close the file similarly file-2 also. Then open the file-1 and write the file-2 data into the file-1, Open the file-2 and write the file-1 data into the file-2 and print the data in the terminal screen.


##RETURN VALUES
	open() : On success it will return open file fd, On failure it will return -1.
	read() : On success it will return number of characters read from the file,On failure it will return -1.
	write() :On success it will return number of characters written,On failure it will return -1.
	close() : On success it will return 0, On failure it will return -1. 

