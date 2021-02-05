#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

char pwd[PATH_MAX];
char path[PATH_MAX];

int main(int argc, char *argv[]) {
    getcwd(pwd, sizeof(pwd));
    printf("%s\n", pwd);
    strcpy(path, getenv("PATH"));
    strcat(path, ":");
    strcat(path, pwd);
    setenv("PATH", path, 1);
    return(0);
}
