#include<stdio.h>
#define MAX 6
int queue[MAX];
int f=-1,r=-1;

void input(){
    if(f==0 && r==MAX-1 || f==r+1 ){
        printf("\nThe Queue is full");
    }
    else{
        if(f==-1){
            f=0;
            r=0;
        }
        else if(r==MAX-1){
            r=0;
        }
        else
            r++;
        printf("\nEnter the Element : ");
        scanf("%d",&queue[r]);
    }
}

void delete(){
    
    if(f==-1){
        printf("\nNo elements in Queue");
    }
    else if(f==r){
        f=-1;
        r=-1;
    }
    else if(f==MAX-1){
        f=0;
    }
    else{
        f++;
    }
}
void display(){
    int L=f,R=r;
    if(f==-1){
        printf("\nQueue is empty");
        return;
    }
    if(L<=R){
        printf("\nQueue : ");
        while(L<=R){
            printf("%d ",queue[L]);
            L++;
        }    
    }
    else{
        printf("\nQueue : ");
        while(L<MAX){
            printf("%d ",queue[L]);
            L++;
        }
        L=0;
        while(L<=R){
            printf("%d ",queue[L]);
            L++;
        }
    }
}

void main(){
    int ele,o=1;
    while(o>0 && o<5){
        printf("\n\n\nSelect an Option :\n1.input elements\n2.delete element\n3.Display\n4.Exit\n");
        scanf("%d",&o);
        if(o==1){
            input();
        }
        else if(o==2){
            delete();
        }
        else if(o==3){
            display();
        }
        else{
            return;
        }
    }
    printf("\n Thank You!!");
} 