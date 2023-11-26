#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define LEN_STR 250

int main(void){
    char countryNames[N][LEN_STR];
    for(int i=0;i<N;i++)
        gets(countryNames[i]);
    for(int i=0;i<N;i++)
        printf("%s\n",countryNames[i]);
    return 0;
}
