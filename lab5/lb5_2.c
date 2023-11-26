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
    for(int i = 0; i < numStr; i++) {
        for(int j=0;j<LEN_STR;j++){
            char lastSymbol=0;
            fscanf(file,"%c",&lastSymbol);
            if(lastSymbol == '\n'|| lastSymbol==0){ 
                strArray[i][j] = '\0';
                break;
            } 
            strArray[i][j] = lastSymbol;
        }
    }
    fclose(file);

    for(int i = 0; i < numStr; i++) {
        puts(strArray[i]);
    }

    for(int i = 0; i < numStr; i++) {
        printf("%c\n", strArray[i][strlen(strArray[i])-1]);
    }
    return 0;
}