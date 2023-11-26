#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calculation(int n, float x, float a){
    double y=0;
    for (int k=0; k<=n; k++)
        y+=pow(x, k)*pow(a, (n-k)/x); 
    return y;
}

int main(void){
    FILE *file;
    file = fopen("input.txt", "r");
    if (file == NULL){
        printf("File not detected.\n");
        exit(1);
    }
    int n;
    float x, a;
    fscanf(file, "%d%f%f", &n, &x, &a);
    double y = calculation(n, x, a);
    printf("The value of the function with the entered values is equal to %f", y);

}