//
//  main.c
//  Question2
//
//  Created by Can Zengin on 10/28/18.
//  Copyright © 2018 Can Zengin. All rights reserved.
//

#include <stdio.h>
int feetq21(int r,int l,int h);
int min(int rl,int rh,int lh);
int feetq22(int r,int l,int h);

int main(int argc, const char * argv[]) {
    FILE *fptr;
    fptr=fopen("input","r+");
    int r,l,h;
    int total=0;
    int totalq22=0;
    char c;
    while(fscanf(fptr,"%d%c%d%c%d",&r,&c,&l,&c,&h)!=EOF){
        total=feetq21(r,l,h)+total;
        totalq22=feetq22(r,l,h)+totalq22;
     }
    printf("answer1:%d\n",total);
    printf("answer2%d",totalq22);
}


int feetq22(int r,int l,int h){
    
     return r*l*h+min(r+r+l+l,r+r+h+h,l+l+h+h);
}
int feetq21(int r,int l,int h){
    
     return 2*r*l+2*l*h+2*h*r+min(r*l,r*h,l*h);
}
int min(int n1,int n2,int n3){
    
    if(n1>n2 || n1>n3){
        if(n2>n3)
            return n3;
        else
            return n2;
    }
    return n1;
    
    
    
}
