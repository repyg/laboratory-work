#include <stdio.h>

int main(void){
    FILE *file;
    file = fopen("input.txt","r");
    int a,b;
    fscanf(file,"%d%d",&a,&b);
    printf("%d %d",a,b);
}