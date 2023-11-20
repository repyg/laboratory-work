#include <stdio.h>
#include <math.h>
 
double function(double x){
     float f = 3*pow(x, 3) - 5*pow(x, 4) - 2*x +3;
     return f;
}

double mult(double minf, double maxf){
    return minf*maxf;
}

int main(void){
    float minf = 10000000000, maxf = - 10000000000;
    for (float x = -8.5; x<=3.7; x+=0.6){
        float f = function(x);
        minf = (minf<f) ? minf : f;
        maxf = (maxf>f) ? maxf : f;
        printf("x = %f\ty = %f\n", x, f);
    }
    printf("The product of the minimum and maximum numbers is equal to %f", mult(minf, maxf));
    return 0;
} 