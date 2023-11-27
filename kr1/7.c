#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_STR 250

int main(void){
    FILE * file;
    char tempStr[LEN_STR];
    int numStr = 0;
    
    file = fopen("text_file.txt", "r");
    if (file==0){
        printf("file not found");
        return 1;
    }
    while(!feof(file)) {
        fgets(tempStr, LEN_STR, file);
        numStr++; 
    }
    fclose(file);

    file = fopen("text_file.txt", "r");
    char ** strArray;
    strArray = (char**)malloc(numStr * sizeof(char*));
    for(int i = 0; i < numStr; i++)
        strArray[i] = (char*)malloc(LEN_STR * sizeof(char));
    fclose(file);

    file = fopen("text_file.txt", "r");
    for(int i = 0; i < numStr; i++) {
        for(int j=0;j<LEN_STR;j++){
            char lastSymbol=0;
            fscanf(file,"%c",&lastSymbol);
            printf("%c",lastSymbol);
            if(lastSymbol == '\n'|| lastSymbol==0){ 
                strArray[i][j] = '\0';
                break;
            } 
            strArray[i][j] = lastSymbol;
        }
    }
    fclose(file);

    file = fopen("text_file.txt", "r");
    char word[LEN_STR];
    int coutWord5=0;
    while (!feof(file)) {
        fscanf(file, "%s ", word);
        int len=0;
        while(word[len]!='\0')
            len++;
        if(len<5)
            coutWord5++;
    }
    fclose(file);
    printf("\n%d", coutWord5);

    char simbol[15]="QEYUIOAqeyuioa";
    int cout=0;
    for(int i=0; i<numStr;i++){
        for(int j=0;j<14;j++){
            if (strArray[i][0]==simbol[j]){
                cout++;
                break;
            }
        }
    }
    printf("\n%d ", cout);
    return 0;
}