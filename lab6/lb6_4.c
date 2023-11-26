#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct hall{
    char nameHall[250];
    int screenDiagonal;
    int numberSeats;
};

struct cinema
{
    char city[250];
    char nameCinemaChain[250];
    char nameCinema[250];
    int numberHalls;
    struct hall Hall[10];
};

int main() {
    struct cinema Cinema[10];
    FILE *file;
    file=fopen("text3.txt","r");
    if (file==0)
        return 1;
    for(int i=0;i<10;i++){
        fscanf(file,"%s",&Cinema[i].city);
        fscanf(file,"%s",&Cinema[i].nameCinemaChain);
        fscanf(file,"%s",&Cinema[i].nameCinema);
        fscanf(file,"%d",&Cinema[i].numberHalls);
        for(int j=0;j<Cinema[i].numberHalls;j++){
            fscanf(file,"%s",&Cinema[i].Hall[j].nameHall);
            fscanf(file,"%d",&Cinema[i].Hall[j].screenDiagonal);
            fscanf(file,"%d",&Cinema[i].Hall[j].numberSeats);
        }
    }

    int maximumNumberHalls=Cinema[0].numberHalls, minimumNumberSeats, maxScreenDiagonal=0;
    for(int i=0;i<1;i++){
        for(int j=0;j<Cinema[i].numberHalls;j++){
            minimumNumberSeats+=Cinema[i].Hall[j].numberSeats;
        }
    }
    for(int i=0;i<10;i++){
        int sumSeats=0;
        maximumNumberHalls=(Cinema[i].numberHalls>maximumNumberHalls)?Cinema[i].numberHalls:maximumNumberHalls;
        for(int j=0;j<Cinema[i].numberHalls;j++){
            sumSeats+=Cinema[i].Hall[j].numberSeats;
            maxScreenDiagonal=(Cinema[i].Hall[j].screenDiagonal>maxScreenDiagonal)?Cinema[i].Hall[j].screenDiagonal:maxScreenDiagonal;
        }
        minimumNumberSeats=(sumSeats<minimumNumberSeats)?sumSeats:minimumNumberSeats;
    }
    printf("cinemas with the maximum number of halls: ");
    for(int i=1;i<10;i++){
        if(Cinema[i].numberHalls==maximumNumberHalls)
            printf("%s.",Cinema[i].nameCinema);
    }
    printf("\ncinemas with a minimum number of seats: ");
    for(int i=0;i<10;i++){
        int sumSeats=0;
        for(int j=0;j<Cinema[i].numberHalls;j++)
            sumSeats+=Cinema[i].Hall[j].numberSeats;
        if(sumSeats==minimumNumberSeats)
            printf("%s; ",Cinema[i].nameCinema);
    }
    printf("\ncinema chains that have only halls with large diagonal screens: ");
    char strSuitableNetworks[250*10];
    for(int i=0;i<10;i++){
        int numberCinemasOneNetwork=0,numberCinemasOneNetworkLargestDiagonal=0;
        for(int j=0;j<10;j++){
            if(strcmp(Cinema[i].nameCinemaChain,Cinema[j].nameCinemaChain)==0){
                numberCinemasOneNetwork++;
                int numberHallsLargeDiagonal=0;
                for(int k=0;k<Cinema[j].numberHalls;k++){
                    if(Cinema[j].Hall[k].screenDiagonal==maxScreenDiagonal){
                        numberHallsLargeDiagonal++;
                    }
                }
                if (numberHallsLargeDiagonal==Cinema[j].numberHalls){
                    numberCinemasOneNetworkLargestDiagonal++;
                }
            }
        }
        if(numberCinemasOneNetwork==numberCinemasOneNetworkLargestDiagonal && strstr(strSuitableNetworks,Cinema[i].nameCinemaChain)==0){
            printf("%s; ",Cinema[i].nameCinemaChain);
            strcat(strSuitableNetworks,Cinema[i].nameCinemaChain);
        }
    }
    
    
}


