#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_STR 250

int main(void){
    char str1[LEN_STR],str2[LEN_STR];
    gets(str1);
    gets(str2);
    char newStr[LEN_STR*2];
    if (strlen(str1)>strlen(str2)){
        strcat(strcpy(newStr,str1),str2);
    }else{
        strcat(strcpy(newStr,str2),str1);
    }
    puts(str1);
    puts(str2);
    puts(newStr);
}