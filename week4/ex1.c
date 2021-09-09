#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	printf("before fork\n");
	pid_t x = fork();
// Firstly parent process would be called, program finishes and runs again because then Child process would be called
	if(x < 0){
		return EXIT_FAILURE;
	}else if(x == 0){
		printf("Hello from child [%d %d]\n", getpid(), x);
	}else{
		printf("Hello from parent [%d %d]\n", getpid(), x);
	}
	printf("after fork\n");
}

