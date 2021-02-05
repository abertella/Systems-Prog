#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h> 

int main(int argc, char *argv[]) {
    pid_t pid, cpid, ppid;
    int status;

    pid = fork();
    if(pid < 0) {
        printf("fork error\n");
        exit(-1);
        }
    if(pid == 0) {
        printf("[CHILD PID] = %d\n[PARENT PID] = %d\n", (cpid = getpid()), (ppid = getppid()));
        sleep(10);
        exit(0);
    }
    else {
        wait(&status);
    }
    return 0;
}