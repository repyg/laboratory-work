#include <stdio.h>

int main(void){
    for (int i = 0; i<10; i++){
        int x;
        scanf("%d", &x);
        if (x < 10)
            printf("0");
        else{
            int x1 = x;
            int numberLengnth = 0;
            while (x1>0){
                numberLengnth += 1;
                x1 /= 10;
                }
            int numberLengthCopy = 1;
            int composition = 1;
            if (numberLengnth == 3)
                composition =(x / 10 % 10);
            while(numberLengthCopy < numberLengnth){
                if (numberLengthCopy == 2 || numberLengthCopy == numberLengnth -1)
                    composition*=(x%10);
                x /= 10;
                numberLengthCopy += 1;
            }
            printf("The product of the second and penultimate digits is equal to %d\n", composition);
        }
    }
    return 0;
}