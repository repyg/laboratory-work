#include <stdio.h>

void print_zero(int a, int b){
    for(int i = ((a % 10) == 0) ? a : (a / 10 + 1) * 10; i <= b; i += 10)
        printf("%d\n", i);
}

int main(void){
    int a, b;
    printf("Enter two integers a and b:");
    scanf("%d %d", &a, &b);
    print_zero(a, b);
    return 0;
}