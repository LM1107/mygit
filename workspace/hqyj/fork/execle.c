#include<stdio.h>
#include<unistd.h>

int main(void)
{	
	int pid = fork();
	if (pid > 0)
	{
		// 父进程
		printf("parent, 子进程id = %d.\n", pid);
		sleep(1);
	}
	else if (pid == 0)
	{
		// 子进程
			/*execlp函数*/
	/*			
		char *envp[]  = {"PATH=/tmp", "USER=David", NULL};	//自己定义的环境变量
		#if 0
		execle("/bin/ls", "ls", "env", NULL, envp);	
		#else
		execle("/bin/ls", "ls", "-l", NULL,NULL);
		#endif
	*/
			/*execvp函数*/
		char *const arg[]   = {"ls","-l", NULL};
		//execvp("/bin/ls", arg);
		execvp("ls", arg);
		return 0;
	}
	else
	{
		perror("fork");
		return -1;
	}	
	return 0;
}