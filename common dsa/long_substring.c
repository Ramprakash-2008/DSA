//This C program finds the length of the longest substring without repeating characters in a given string.
/*
enter the size of string: 10
enter the string: abcabcbb
longest substring is: 3*/
#include<stdio.h>
#include <stdio.h>
#include <string.h>

int longsubstring(char a[]) {
    int n = strlen(a);
    int max = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;
                    for (int j = i; j < n; j++) {
            int repeat = 0;

            // Check whether a[j] already exists
            // between i and j-1
            for (int k = i; k < j; k++) {
                if (a[k] == a[j]) {
                    repeat = 1;
                    break;
                }
            }

            if (repeat)
                break;

            count++;
        }

        if (count > max)
            max = count;
    }

    return max;
}
int main(){
    int n;
    printf("enter the size of string");
    scanf("%d",&n);
    char a[n];
    printf("enter the string  ");
    scanf("%s",a);
    printf("longest substring is: %d",longsubstring(a));
    return 0;
}
