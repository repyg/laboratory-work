#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    FILE *file;
    file=fopen("output1.txt","w");
    if(file==0)
        return 1;
    int N=5;
    srand(time(NULL));
    for(int i=0;i<N;i++)
        fprintf(file,"%d\n", -100 +rand()%200);
    fclose(file);

    file=fopen("output1.txt", "a+");
    char str[30]="I like such interesting tasks";
    int M=5;
    for(int i = 0; i < M; i++) {
        fprintf(file, "%s\n", str);
    }
    fclose(file);


    
}