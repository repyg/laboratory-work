#define N 10
#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *file;
    file = fopen("input.txt", "r");
    if (file == NULL){
        printf("File not detected.\n");
        exit(1);
    }
    int a[N];
    for(int i=0; i<N; i++)
        fscanf(file, "%d", &a[i]);
    
    int lasti=N, lastNumber=0, penultimateNumber=0;
    for(int i=0; i<10; i++){
        int productLastDigits=0;
        if(i==0)
             productLastDigits=a[i+1]%10;
        else if(i==(N-1))
            productLastDigits=a[i-1]%10;
        else
            productLastDigits=(a[i+1]%10)*(a[i-1]%10);

        if (productLastDigits==0){
            lasti=i;
            break;
        }else{
            if(i>1)
                a[i-2] = penultimateNumber;    
            penultimateNumber = lastNumber;
            lastNumber=a[i]/productLastDigits;
        }
    }
    a[N-2] = penultimateNumber;
    penultimateNumber = lastNumber;
    a[N-1] = penultimateNumber;
        
    for(int i=0; i<lasti; i++){
        printf("%d\t",a[i]);
    }
    return 0;
}