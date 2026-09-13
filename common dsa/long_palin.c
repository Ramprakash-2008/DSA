//This C program finds the Longest Palindromic Substring in a given string.
/*
Input:
enter the string : babad
Output:
longest palindrome: bab
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* longestPalindrome(char* s){
     int maxLength = 0;
    int start = 0;

    for(int i=0;i<strlen(s);i++){
        for(int j=i;j<strlen(s);j++){
            if(s[i]==s[j]){
                int k=i;
                int l=j;
                while(k<=l){
                    if(s[k]!=s[l]){
                        break;
                    }
                    k++;
                    l--;
                }
                if(k>l){
                     int length = j - i + 1;

                    if(length > maxLength)
                    {
                        maxLength = length;
                        start = i;//printf("%d %d\n",i,j);
                }
            }
        }
    }
        } 

    char* result = (char*)malloc(sizeof(char) * (maxLength + 1));
    for(int i=0;i<maxLength;i++){
        result[i] = s[start + i];
    }
    result[maxLength] = '\0';
    return result;}
int main(){
    char* s = (char*)malloc(sizeof(char) * 1000);
    printf("enter the string : ");
    scanf("%s",s);
    printf("longest palindrome: %s",longestPalindrome(s)) ;
}    