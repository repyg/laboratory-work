#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_STR 250

int main(void){
    char str[LEN_STR], newStr[LEN_STR];
    gets(str);
    strcat(strcpy(newStr,str),str);
    printf("\n%s\n%s",str,newStr);
    return 0;
}
