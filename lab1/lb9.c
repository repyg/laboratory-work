#include <stdio.h>
#include <string.h>

const char allConsonantLetters[45] = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstwxyz";

int main(void){
    char name[10][50];
    for(int i=0; i<10; i++){
        printf("Enter a name: ");
        scanf("%s", name[i]);
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<44; j++){
            if (allConsonantLetters[j] == name[i][1])
                printf("%s\n", name[i]);
        }
    }
    return 0;
}