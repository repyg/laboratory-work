#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_STR 250

int main(void){
    FILE * file;
    file = fopen("text.txt", "r");
    if (file==0){
        printf("file not found");
        return 1;
    }
    char word[LEN_STR];
    int characterRepeated2 = 0;
    while (!feof(file)) {
        fscanf(file, "%s ", word);
        for(int j = 0; j < strlen(word) / 2; j++) {
            char copyElement=word[j];
            word[j]= word[strlen(word) - 1 - j];
            word[strlen(word)-1-j]=copyElement;
        }
        printf("%s\n",word);
        for(int j = 0; j < strlen(word)-1; j++) {
            if(word[j]==word[j+1])
                characterRepeated2++;
        }
    }
    printf("\nThe number of elements repeated twice is equal to %d.", characterRepeated2);
    fclose(file);
    return 0;
}