#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#invlude<sys/wait.h>

int main(){
pid_t pid = fork();
if (pid < 0){
	printf("Fork fail");
	exit(0);
}
else if (pid == 0){
	execl("./child", "child", (char *)NULL);
}

int status;

waitpid(pid, &status, 0);

if (WIFEXITED(status))
{
int exit_status = WEXITSTATUS(status);
printf("A gyermek kilepesi erteke: %d\n", exit_status);
}
return 0;
}