#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    while(true){
        int x;
        scanf("%d",&x);
            if (x < 100 && x > 9 && (x % 10 + x / 10) > 10){
            float x1 = x;
            while (x1 < 500){
                float y = (float) rand() / RAND_MAX;
                printf("%f + %f = %f\n", x1, y, x1+y);
                x1 += y;
            }
        }
    }
    return 0;
}