#include <stdlib.h>
#include <string.h>

int main(void){
    char str[3][50];
    for(int i=0; i<3; i++){
        printf("Enter the lines: ");
        gets(str[i]);
    }
    char newStr[6][150];
    int numberStr=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3;j++){
            for(int k=0;k<3;k++){
                if (i!=j && j!=k && i!=k){
                    char strx[150];
                    strcat(strcat(strcpy(strx, str[i]), str[j]), str[k]);
                    strcpy(newStr[numberStr], strx);
                    numberStr+=1;
                }
            }
        }
    }
    for(int i=0; i<3; i++)
        printf("the entered string %s\n", str[i]);
    for(int i=0; i<6; i++)
        printf("the new string %s\n", newStr[i]);
    return 0;
}