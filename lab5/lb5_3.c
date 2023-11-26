#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_STR 250

int main(void){
    FILE * file;
    char tempStr[LEN_STR];
    int numStr = 0;
    file = fopen("text.txt", "r");
    if (file==0){
        printf("file not found");
        return 1;
    }
    while(!feof(file)) {
        fgets(tempStr, LEN_STR, file);
        numStr++;
    }
    fclose(file);

    file = fopen("text.txt", "r");
    char ** strArray;
    strArray = (char**)malloc(numStr * sizeof(char*));
    for(int i = 0; i < numStr; i++)
        strArray[i] = (char*)malloc(LEN_STR * sizeof(char));
    fclose(file);

    file = fopen("text.txt", "r");
    char lastSymbol = 0;
    for(int i = 0; i < numStr; i++) {
        fgets(strArray[i], LEN_STR, file);
        lastSymbol = strArray[i][strlen(strArray[i]) - 1];
        if(lastSymbol == '\n') {
            strArray[i][strlen(strArray[i]) - 1] = '\0';
        }
    }
    fclose(file);
    char textCharacters[16]="!#№,.:;?*()-_=+";
    file = fopen("text.txt", "a+");
    char word[LEN_STR];
    int numberWords = 0;
    while (!feof(file)) {
        fscanf(file, "%s", word);
        for(int j=0;j<16;j++){
            if (word[strlen(word)-1]==textCharacters[j])
                word[strlen(word)-1]='\0';
            }
        if (strlen(word) < 8)
            numberWords++;
        printf("%s\n", word);
    }
    fprintf(file,"\nnumber of rows=%d\tthe number of words shorter than 8 characters = %d\n",numStr,numberWords);
    fclose(file);
    return 0;
}