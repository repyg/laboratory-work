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
    int lenStr=0;
    char textCharacters[16]="!#№,.:;?*()-_=+",capitalLetters[27]="QWERTYUIOPASDFGHJKLZXCVBNM",letters[27]="qwertyuiopasdfghjklzxcvbnm";

    char word[LEN_STR][LEN_STR];
    while (!feof(file)) {
        fscanf(file, "%s ", &word[lenStr]);
        for(int j=0;j<16;j++){
            if (word[lenStr][strlen(word[lenStr])-1]==textCharacters[j])
                word[lenStr][strlen(word[lenStr])-1]='\0';
            }
        for(int j=0;j<27;j++){
            if (word[lenStr][0]==capitalLetters[j])
                word[lenStr][0]=letters[j];
            }
        
        lenStr++;
    }
    fclose(file);

    for(int i=0;i<lenStr;i++){
        for(int j=i+1;j<lenStr;j++){
            printf("letters matching in location: ");
            for(int k=0;k<27;k++){
                if(strchr(word[i],letters[k])!=0 && strchr(word[j],letters[k])!=0)
                    printf("%c ", letters[k]);   
            }
            printf("\nIdentical letters standing in the same places: ");
            if(strlen(word[i])<strlen(word[j])){
                for(int k=0;k<strlen(word[i]);k++){
                    if (word[i][k]==word[j][k])
                        printf("%c ", word[i][k]);
                }
            }else{
                for(int k=0;k<strlen(word[j]);k++){
                    if (word[j][k]==word[i][k])
                        printf("%c ", word[j][k]);
                }
            }
            printf("\n%s %s\n\n",word[i],word[j]);
        }
    }

    return 0;
}