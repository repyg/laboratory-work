#include <stdio.h>
#include <math.h>
#include <string.h> 

struct butterflies{
    char butterflyType[50];
    char nameButterfly[50];
    int yearOpening;
    char habitatHalo[50];
    int populationSize;
};

int main(void){
    struct butterflies Butterflies[10];
    FILE *file;
    file=fopen("text1.txt","r");
    if (file==0)
        return 1;
    for (int i = 0; i < 10; i++){
        fscanf(file,"%s %s %d %s %d",&Butterflies[i].butterflyType,&Butterflies[i].nameButterfly,
        &Butterflies[i].yearOpening,&Butterflies[i].habitatHalo,&Butterflies[i].populationSize);
    }

    char type[50];
    int maxPopulationSize=Butterflies[0].populationSize;
    for (int i = 0; i < 10; i++){
        int sum=Butterflies[i].populationSize;
        for(int j=i+1;j<10;j++){
            if(strcmp(Butterflies[i].butterflyType, Butterflies[j].butterflyType)==0)
                sum+=Butterflies[j].populationSize;
        }
        if(sum>maxPopulationSize){
            maxPopulationSize=sum;
            strcpy(type,Butterflies[i].butterflyType);
        }
    } 
    printf("%s %d\n", type, maxPopulationSize);
    char introducedHalo[50];
    scanf("%s", &introducedHalo);
    for(int i=0;i<10;i++){
        if(strcmp (introducedHalo, Butterflies[i].habitatHalo)==0)
            printf("%s\n",Butterflies[i].nameButterfly);
    }
}