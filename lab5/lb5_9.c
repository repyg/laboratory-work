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

    char str[LEN_STR*numStr];
    char letters[LEN_STR]="QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm.,/!@#1234567890:;";
    file = fopen("text.txt", "r");
    for(int i = 0; i < numStr; i++) {
        fgets(strArray[i], LEN_STR, file);
        if(strArray[i][strlen(strArray[i]) - 1] == '\n') {
            strArray[i][strlen(strArray[i]) - 1] = '\0';
        }
        strcat(str, strArray[i]); 
    }
    fclose(file);
    
    FILE *out;
    out=fopen("output.txt","w");
    fprintf(out,"letters found in the text ");
    for(int i=0;i<strlen(letters);i++){
        if(strchr(str,letters[i])!=0) 
            fprintf(out,"%c ", letters[i]);
    }


}