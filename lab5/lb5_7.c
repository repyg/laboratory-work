#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_STR 250

int main(void){
    char sentence[LEN_STR]="We have committed the Golden Rule to memory; let us now commit it to life.";
    char CapitalVowels[7]="EYUIOA",vowels[7]="eyuioa",vowelsPresentSentence[7]="000000";
    int count=0, lenStr=0;

    for(int i=0;i<strlen(sentence);i++){
        for(int j=0;j<7;j++){
            if (sentence[i]==CapitalVowels[j])
                sentence[i]=vowels[j];
        }
        lenStr++;
    }

    for(int i=0;i<lenStr;i++){
        for(int j=0;j<7;j++){
            if (sentence[i]==vowels[j]){
                count++;
                for(int k=0;k<8;k++){
                    if (vowels[j]==vowelsPresentSentence[k])
                        break;
                    if (vowelsPresentSentence[k]=='0'){
                        vowelsPresentSentence[k]=vowels[j];
                        break;
                    }
                }
            }
        }
    }
    printf("%s\nvowels in a sentence %d and the vowels present in the sentence are %s",sentence,count,vowelsPresentSentence);
    return 0;

}