#include <stdio.h>
#include <math.h>

float func(float x){
    return 3 * pow(x, 3) - 5 * pow(x, 4) - 2 * x +3; 
}

int main(void){
    float minf = func(-8.5), maxf = func(-8.5);
    for (float x = -8.5; x <= 3.7; x += 0.6){
        float f = func(x);
        minf = (minf<f) ? minf : f;
        maxf = (maxf>f) ? maxf : f;
        printf("x = %f\ty = %f\n", x, f);
    }
    printf("The product of the minimum and maximum numbers is equal to %f", minf * maxf);
    return 0;
}