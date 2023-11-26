#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    srand(time(NULL));
    int N=10+rand()%200;
    char str[N];
    for (int i = 0; i < N - 1; i++)
        if (rand()%7)
            str[i] = (rand()%10) ?'a' + rand()%26 :' ';
        else
            str[i] = (rand()%10) ?'A' + rand()%26 :' ';
    str[N-1]='\0';
    puts(str);
    return 0;
}