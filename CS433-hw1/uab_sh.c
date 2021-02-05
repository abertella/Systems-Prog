/*
Name: Andrew Bertella
BlazerId: berba
A simple shell implimentation with some built in commands and the ability to execute binaries in the PATH or the local directory
hw1 - uab_sh
*/

#include <dirent.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/wait.h>
#include <unistd.h>
#include "uab_sh.h"

const char* const prompt_str = "uab_sh> ";
int argcount = 0;
pid_t pid;
char *args[10];
char pwd[PATH_MAX], path[PATH_MAX];
FILE *fptr;
char *linebuff = NULL;

static void prompt();
static int parse_input(char *line);
static void exec_cmd();
static void quit();
static void list();
static void cd();
static void help();
static void history();

int main(int argc, char *argv[]) {
    getcwd(pwd, sizeof(pwd));                           //Initialize pwd
    getcwd(pwd, sizeof(pwd));
    strcpy(path, getenv("PATH"));
    strcat(path, ":");
    strcat(path, pwd);
    setenv("PATH", path, 1);
    fptr = fopen("history.log", "w+");          
    prompt();
    return 0;
}

static void prompt() {
    //A function to prompt the user for input
    size_t llen = 0;
        while(true){
        printf("%s", prompt_str);               
        if ((getline(&linebuff, &llen, stdin)) >  1) {      //Read a line from stdin
            fprintf(fptr, "%s", linebuff);                  //print it to history
            fflush(fptr);                                   //flush
            argcount = parse_input(linebuff);               //parse the input into args vector
            exec_cmd();                                     //execute the command
        } else {                                            //if our input length is <2 (only a \n), we prompt again
            prompt();       
        }
    }
}

static int parse_input(char* line) {
    //put arguments from job command into the argument vector
	int i, count, length;
    length = strlen(line);
    line[length - 1] = '\0';
	for (i = 0, args[0] = &line[0], count = 1; i < length; i++) {
		if (line[i] == ' ') {
		   line[i] = '\0';
		   args[count++] = &line[i+1];
		}
	}
	args[count] = (char *)NULL;
    return count;
}

static void exec_cmd() {
    //A function to execute the commands and parameters found in the args vector
    int status;

    if(strcmp(args[0], "quit") == 0) {
        quit();
    } else if(strcmp(args[0], "list") == 0) {
        list();
    } else if(strcmp(args[0], "cd") == 0) {
        cd();
    } else if(strcmp(args[0], "help") == 0) {
        help();
    } else if(strcmp(args[0], "history") == 0) {
        history();
    } else {
        pid = fork();
        if (pid == 0) {                                 //Child process
            execvp(args[0], args);                      //Try to execute command
            printf("Could not execute command %s\n", args[0]);
            exit(-1);
        } else if (pid > 0) {
            wait(&status);                              //Wait for child to complete
        }
    }
}

static void quit() {
    //Quits the program
    free(linebuff);
    fclose(fptr);                                       //Close the log file
    exit(0);
}

static void list() {
    //Lists the files in the current directory
    struct dirent *dirp;
    DIR *dp;
    dp = opendir(pwd);
    while((dirp = readdir(dp)) != NULL) {           //Read the directory entries
        printf("%s\n", dirp->d_name);               //Print them one per line
    }
}

static void cd(){
    //Changes the pwd and the cwd enviroment variable to the directory specified
    if (argcount != 2) {
        printf("Usage = %s <new_directory>\n", args[0]); //Invalid input
    }
    else {
        chdir(args[1]);                             //Change the enviroment variable
        getcwd(pwd, sizeof(pwd));                   //Change local pwd variable
    }
}

static void help() {
    //Prints the help message found in blazersh.h
    printf("%s", help_mess);
}

static void history() {
    //Prints the history from the history.log file.
    char *line = NULL;
    size_t llen = 0;
    fseek(fptr, 0, SEEK_SET);                       //read from the beginning of the file
    while(getline(&line, &llen, fptr) != EOF) {
        printf("%s", line);
    }
    free(line);
}