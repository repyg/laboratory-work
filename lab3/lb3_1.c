#define N 10
 #include <stdio.h>

 int main(void){
    int a[N];
    int A=10, B=31;
    for(int i=0; i<N; i++)
        a[i]=A+i;
    
    double b[N];
    double C=0, D=1.1;
    for(int i=0 ; i<N; i++)
        C+=0.1;
        b[i]=C;

    for(int i=0; i<10;i++)
        printf("array_int[%d] = %d;\tarray_double[%d] = %.2f\n", i, a[i], i, b[i]);


    return 0;
 }