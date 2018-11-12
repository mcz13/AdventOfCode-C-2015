//
//  main.c
//  Question2
//
//  Created by Can Zengin on 10/28/18.
//  Copyright © 2018 Can Zengin. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
void toggle(int lamps[1000][1000],int fromx,int fromy,int tox,int toy);
void turnon(int lamps[1000][1000],int fromx,int fromy,int tox,int toy);
void turnoff(int lamps[1000][1000],int fromx,int fromy,int tox,int toy);

void main(void){
    int lits=0;
    int lamps[1000][1000];
  
    for(int i=0;i<1000;i++)
        for(int n=0;n<1000;n++)
            lamps[i][n]=0;
    FILE *fptr=fopen("input", "r");
     char c;
    char array[20],array2[20];
     int fromx,fromy,tox,toy;
  
    
    while (fscanf(fptr,"%s",array)!=EOF) {
        
        if(!strcmp(array,"toggle")){
            fscanf(fptr, "%d %c %d %s %d %c %d",&fromx,&c,&fromy,array2,&tox,&c,&toy);
            toggle(lamps,fromx,fromy,tox,toy);
        }
        else{
            fscanf(fptr,"%s",array2);
            if(!strcmp(array2,"on")){
                fscanf(fptr, "%d %c %d %s %d %c %d",&fromx,&c,&fromy,array2,&tox,&c,&toy);
                turnon(lamps,fromx,fromy,tox,toy);
            }
            else{
                fscanf(fptr, "%d %c %d %s %d %c %d",&fromx,&c,&fromy,array2,&tox,&c,&toy);
                turnoff(lamps,fromx,fromy,tox,toy);
            }
        }
    }
    for(int i=0;i<1000;i++)
        for(int n=0;n<1000;n++)
              lits+=lamps[i][n];
    printf("%d",lits);
    
}
void toggle(int lamps[1000][1000],int fromx,int fromy,int tox,int toy){
    for(int i=fromx;i<=tox;i++)
        for(int n=fromy;n<=toy;n++)
              lamps[i][n]+=2;
    
    
}
void turnon(int lamps[1000][1000],int fromx,int fromy,int tox,int toy){
    
    for(int i=fromx;i<=tox;i++)
        for(int n=fromy;n<=toy;n++)
               lamps[i][n]+=1;
    
    
    
}

void turnoff(int lamps[1000][1000],int fromx,int fromy,int tox,int toy){
    
    for(int i=fromx;i<=tox;i++)
        for(int n=fromy;n<=toy;n++)
            if(lamps[i][n]!=0)
            lamps[i][n]-=1;
    
    
    
}
