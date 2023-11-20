#define A -110
#define B 10
#define N B-A+1

#include <stdio.h>

int main(void){
    int a[N];
    for(int i=A;i<=B;i++)
        a[i-A]=i;
    int b=0;
    for(int i=B-A;i>=0;i--){
        if (a[i]%2==0 && a[i]<0){
            printf("%d\t", a[i]);
            b+=1;
        }
        if (b==4)
            break;
    }
    if (b==0)
            printf("no set numbers were found");
    
    return 0;
}