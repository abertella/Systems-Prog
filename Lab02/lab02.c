/* 
A program to delete duplicate integers in a given array
@author Andrew Bertella
*/

#include<stdio.h>

#define SIZE 8

static int in_arr(int n, int arr[], int count);

int main()
{
    int i, count = 0, retArray[SIZE];
    int testArray[] = {29, 17, 8, 17, 9, 17, 29, 9};
    
    for(i = 0; i < SIZE; i++) {
        if(!in_arr(testArray[i], retArray, count)) {
            retArray[count++] = testArray[i];
        }
    }

    printf("[");
    for(i = 0; i < count; i++) {
        if(i == count - 1){
            printf("%d]\n", retArray[i]);
        }
        else {
            printf("%d, ", retArray[i]);
        }
    }
    return 0;   
}

static int in_arr(int n, int arr[], int count) {
    int i;
    for(i = 0; i < count; i++) {
        if(arr[i] == n) {
            return 1;
        }
    }
    return 0;
}