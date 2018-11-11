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

void main(void){
    FILE * fptr=fopen("input","r");
    char array[16]=" ";
    int nice=0;
    while(fscanf(fptr,"%s", array)!=EOF){
        int cond1=0;
        int cond2=0;
        for(int i=0;i<=13;i++){
            if(array[i]==array[i+2]){
              
                cond1++;}
         }
        for(int n=0;n<=14;n++){
            for(int z=0;z<=14;z++){
                if(z!=n && z!=n+1 && z>n && array[z]==array[n] && array[z+1]==array[n+1]){
                    cond2++;
                    
                }
                
            }
        }
        if (cond1!=0 && cond2!=0 ) {
            nice++;
        }
    }
   
    printf("%d",nice);
    
    
    
}
