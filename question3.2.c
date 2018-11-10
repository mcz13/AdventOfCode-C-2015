

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
struct kordinat{
    int x;
    int y;
    
    struct kordinat *next;
    
};
static int oncekix=0;
static int oncekiy=0;
static int oncekixx=0;
static int oncekiyy=0;
static int total=0;
void add(int,int,struct kordinat **,int wadd);
void main(void){
    struct kordinat *head=NULL;
    add(oncekix,oncekiy,&head,0);
    FILE *fptr;
    fptr=fopen("input","r+");
    char c;
    int counter=0;
    while((c=fgetc(fptr))!=EOF){
        if(counter%2==0){
        if(c=='<')
            add(-1+oncekix,0+oncekiy,&head,0);
        else if(c=='>')
            add(1+oncekix,0+oncekiy,&head,0);
        else if(c=='^')
            add(0+oncekix,1+oncekiy,&head,0);
        else if(c=='v')
            add(0+oncekix, -1+oncekiy, &head,0);
        }
        else{
            if(c=='<')
                add(-1+oncekixx,0+oncekiyy,&head,1);
            else if(c=='>')
                add(1+oncekixx,0+oncekiyy,&head,1);
            else if(c=='^')
                add(0+oncekixx,1+oncekiyy,&head,1);
            else if(c=='v')
                add(0+oncekixx, -1+oncekiyy, &head,1);
            
        }
        
        counter++;
    }
    printf("%d",total);
    
}

void add(int x,int y,struct kordinat ** headref,int santa){
    struct kordinat *iter=*headref;
    struct kordinat *newnode=(struct kordinat *)malloc(sizeof(struct kordinat));
    newnode->x=x;
    newnode->y=y;
    newnode->next=NULL;
    if(iter==NULL){
        if(santa==0){
        oncekiy=y;
        oncekix=x;
            
        }
        else if(santa==1){
            oncekiyy=y;
            oncekixx=x;
        }
        total++;
        *headref=newnode;}
    else{
        while(iter->next!=NULL){
            if(iter->x==x && iter->y==y){
                 if(santa==0){
                    oncekiy=y;
                    oncekix=x;
                    
                }
                else if(santa==1){
                    oncekiyy=y;
                    oncekixx=x;
                }
                return;
                
            }
            
            iter=iter->next;
            if(iter->x==x && iter->y==y){
                if(santa==0){
                    oncekiy=y;
                    oncekix=x;
                    
                }
                else if(santa==1){
                    oncekiyy=y;
                    oncekixx=x;
                }
                return;
                
            }
            
        }
        if(santa==0){
            oncekiy=y;
            oncekix=x;
            
        }
        else if(santa==1){
            oncekiyy=y;
            oncekixx=x;
        }
        total++;
        iter->next=newnode;
        
    }
    
    
    
}
