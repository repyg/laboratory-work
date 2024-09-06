#include <stdio.h>  
#include <stdlib.h>

int main(void){                                  
    FILE *file;
    file = fopen("data.txt", "r");
    if (file == NULL){
        printf("File not detected.\n");
        return 1;
    }
    int a, b;
    fscanf(file, "%d %d", &a, &b);
    for(int i = ((a % 10) == 0) ? a : (a / 10 + 1) * 10; i <= b; i += 10){
        printf("%d\t", i);
    }
    return 0;
}   