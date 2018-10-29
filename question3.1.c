//
//  main.c
//  Question2
//
//  Created by Can Zengin on 10/28/18.
//  Copyright © 2018 Can Zengin. All rights reserved.
//

#include <stdio.h>
struct kordinat{
    int x;
    int y;
  
   struct kordinat *next;

};
static int oncekix=0;
static int oncekiy=0;
static int total=0;
void add(int,int,struct kordinat **);
    void main(void){
        struct kordinat *head=NULL;
        add(oncekix,oncekiy,&head);
        FILE *fptr;
        fptr=fopen("input","r+");
        char c;
        while((c=fgetc(fptr))!=EOF){
            if(c=='<')
                add(-1+oncekix,0+oncekiy,&head);
             else if(c=='>')
                 add(1+oncekix,0+oncekiy,&head);
            else if(c=='^')
                add(0+oncekix,1+oncekiy,&head);
            else if(c=='v')
                add(0+oncekix, -1+oncekiy, &head);
                
         }
        printf("%d",total);
        
    }
    
void add(int x,int y,struct kordinat ** headref){
    struct kordinat *iter=*headref;
    struct kordinat *newnode=(struct kordinat *)malloc(sizeof(struct kordinat));
    newnode->x=x;
    newnode->y=y;
    newnode->next=NULL;
    if(iter==NULL){
        oncekiy=y;
        oncekix=x;
        total++;
        *headref=newnode;}
 else{
     while(iter->next!=NULL){
         if(iter->x==x && iter->y==y){
             printf("--%d--",x);
             printf("--%d--",y);
             oncekiy=y;
             oncekix=x;
             return;
             
         }
         
     iter=iter->next;
         if(iter->x==x && iter->y==y){
              oncekiy=y;
             oncekix=x;
             return;
             
         }
       
      }
   
     oncekiy=y;
     oncekix=x;
     total++;
     iter->next=newnode;
     
  }
    
    
    
}
