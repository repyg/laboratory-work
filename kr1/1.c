#include <stdio.h>
#include <math.h>
#define N 7


int main(void){
    FILE *file;
    file=fopen("input.txt","r");
    if(file==0)
        return 1;
    int array[N];
    for(int i=0;i<N;i++){
        fscanf(file,"%d",&array[i]);
    }
    float newArray[N];
    for(int i=0;i<N;i++){
        if (array[i]>0){
            float sumNumber=0;
            int coutNumber=0;
            int copyArray=array[i];
            while(copyArray>0){
                sumNumber+=copyArray%10;
                coutNumber++;
                copyArray/=10;
            }
            newArray[i]=(float)(array[i]+sumNumber/coutNumber);
        }else if(array[i]<0){
            int lastNumber=0;
            int copyArray=abs(array[i]);
            while(copyArray>0){
                lastNumber=copyArray;
                copyArray/=10;
            }
            newArray[i]=(float)(array[i]-lastNumber);
        }else{
            newArray[i]=0;
        }
    }
    for(int k=0;k<N;k++){
        for(int i=0;i<N-k-1;i++){
            if(newArray[i]<newArray[i+1]){
                float copy = newArray[i];
                newArray[i]=newArray[i+1];
                newArray[i+1]=copy;
            }
        }
    }

    for(int i=0;i<N;i++){
        printf("%.1f ", newArray[i]);
    }
    return 0;
}