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
        
        int vovel=0;
        int repeat=0;
        if(array[15]=='a' || array[15]=='e' ||array[15]=='i' ||array[15]=='o'||array[15]=='u' ){
            vovel++;
        }
        for(int i=0;i<=14;i++){
            if(array[i]==array[i+1]){ repeat++;}
               
            if((array[i]=='a'&&array[i+1]=='b') || (array[i]=='c'&&array[i+1]=='d') ||
               (array[i]=='p'&&array[i+1]=='q')|| (array[i]=='x'&&array[i+1]=='y')){
                vovel=0;
                repeat=0;
                
                break;}
    
            if(array[i]=='a' || array[i]=='e' ||array[i]=='i' || array[i]=='o'|| array[i]=='u' ){
                vovel++;
            }
          
        }
  
        if(vovel>=3 &&  repeat>0)
            nice++;
    }
   
    printf("%d",nice);
    
    
    
}
