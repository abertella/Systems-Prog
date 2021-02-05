/*
An array based implimentation of a Fibonacci generator
@author Andrew Bertella (berba)
17 Jabuary 2020
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100       //This should be greater than the 64-bit representation of a llu
#define MAX_FIB 94         //The largest Fibonacci that can be represented in 64 bits

static void fib(int n);
static void print_array(int n);

unsigned long long fib_arr[MAX_SIZE];

int main(int argc, char** argv) {
    int given_number;

    if(argc != 2) {
        printf("Usage %s <n>\n", argv[0]);
        exit(0);
    }

    given_number = atoi(argv[1]);   

    if(given_number > MAX_FIB) {
        printf("This number is too big to represent in 64 bits! Exiting...\n");
        exit(0);
    }
    fib(given_number);
    printf("The first %d Fibonacci number(s) are:\n" , given_number);
    print_array(given_number);

    return(0);
}

static void fib(int n) {
    //Populates the array with the first n Fibonacci numbers
    int i;

    fib_arr[0] = 0;
    fib_arr[1] = 1;

    for(i = 2; i < n; i++) {
        fib_arr[i] = fib_arr[i-2] + fib_arr[i-1];
    }
}

static void print_array(int n) {
    //Prints the array with the first n Fibonacci numbers
    int i;

    for(i = 0; i < n; i++) {
        if(i == (n - 1)) {
            printf("%llu\n", fib_arr[i]);
        }
        else {
            printf("%llu, ", fib_arr[i]);
        }
    }
}