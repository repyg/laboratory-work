#define N 100
#include <stdio.h>
#include <math.h>

double averageValue(int array[]){
    int sumx=0, count=0;
    for(int i=0;i<N;i++){
        if(array[i]>0){
            sumx+=array[i];
            count+=1;
        }
    }
    return ((double)sumx/count);
}

int numberOfNumbersGreaterAverageValue(int array[], double average){
    int count=0;
    for(int i=0;i<N;i++){
        if (array[i]>average)
            count+=1;
    }
    return count;
}

int sumOfDigits(int a){
    a=abs(a);
    int sum=0;
    while (a>0){
        sum+=(a%10);
        a/=10;
    }
    return sum;
}

int sumOfTheDigitsMinimumNumber(int array[]){
    int min=1000000000;
    for (int i=0;i<N;i++)
        min=(array[i]<min)?array[i]:min;
    return sumOfDigits(min);
}

int maximumElementMultiple7(int array[]){
    int max=0;
    for (int i=0;i<N;i++)
        max=(array[i]>max && array[i]%7==0)?array[i]:max;
    return max;
}

int main(void){
    int a[N];
    int A=-50, B=100;
    for(int i=0;i<N;i++)
        a[i]=A+i;
    printf("%d\n",numberOfNumbersGreaterAverageValue(a,averageValue(a)));
    printf("%d\n",sumOfTheDigitsMinimumNumber(a));
    printf("%d\n",maximumElementMultiple7(a));
}