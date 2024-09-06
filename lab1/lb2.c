#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    FILE *file;
    file = fopen("lb2.txt", "w");
    srand(time(NULL));
    for (int i = 0; i < 10; i++){
        int x = rand(), x1 = rand();
        int max = (x > x1) ? x : x1;
        fprintf(file, "%d\t", max);
        if (i % 2 == 1)
            fprintf(file, "\n");
    }
    return 0;
}