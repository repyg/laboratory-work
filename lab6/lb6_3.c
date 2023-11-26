#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct theme {
    char topic[250];
    int bookCount;
};

struct library{
    char name[250];
    char title[250];
    float area;
    int themeCount;
    struct theme Themes[10];
    int subscriptionCount;
    int dailyVisitors;
};

int main() {
    struct library Library[10];
    FILE *file;
    file=fopen("text2.txt","r");
    if (file==0)
        return 1;
    for(int i=0;i<10;i++){
        fscanf(file,"%s",&Library[i].name);
        fscanf(file,"%s",&Library[i].title);
        fscanf(file,"%f",&Library[i].area);
        fscanf(file,"%d",&Library[i].themeCount);
        for(int j=0;j<Library[i].themeCount;j++){
            fscanf(file,"%s",&Library[i].Themes[j].topic);
            fscanf(file,"%d",&Library[i].Themes[j].bookCount);
        }
        fscanf(file,"%d",&Library[i].subscriptionCount);
        fscanf(file,"%d",&Library[i].dailyVisitors);
    }
    int min=(int) INFINITY,index;
    float popularityLibrary=0;
    for(int i=0;i<10;i++)
        min=(Library[i].subscriptionCount<min)?Library[i].subscriptionCount:min;

    for(int i=0;i<10;i++){
        if(Library[i].subscriptionCount==min && popularityLibrary<((float)Library[i].dailyVisitors/Library[i].subscriptionCount)){
            popularityLibrary=((float)Library[i].dailyVisitors/Library[i].subscriptionCount);
            index=i;
        }
    }
    printf("%.4f %s",popularityLibrary,Library[index].name);

    char nameLibrary[10][250];
    float areaLibrary[10];
    for(int i=0;i<10;i++){
        strcpy(nameLibrary[i],Library[i].name);
        areaLibrary[i]=Library[i].area;
    }
    for(int k=0;k<9;k++){
        for(int i=0;i<9-k;i++){
            if(areaLibrary[i]<areaLibrary[i+1]){
                float copy=areaLibrary[i];
                areaLibrary[i]=areaLibrary[i+1];
                areaLibrary[i+1]=copy;
                char copyStr[250];
                strcpy(copyStr,nameLibrary[i]);
                strcpy(nameLibrary[i],nameLibrary[i+1]);
                strcpy(nameLibrary[i+1],copyStr);
            }
        }
    }
    for(int i=0;i<10;i++){
        printf("%s %.1f\n",nameLibrary[i],areaLibrary[i]);
    }
    return 0;
}