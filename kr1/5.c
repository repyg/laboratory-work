#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LEN_STR 250

int main(void){
    char str1[LEN_STR];
    gets(str1);
    int len=0;
    while(str1[len]!='\0'){
        len++;
    }
    printf("%d ", len);
    srand(time(0));
    int randomNumber=rand()%len;
    printf("\n%d %c ",randomNumber,str1[rand()%len]);
}