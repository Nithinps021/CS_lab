#include<stdio.h>
#define MAX 5

int ar[MAX];
int s1t=-1,s2t=-1;

void push1(){
    if(s1t+1==s2t||s1t+1==MAX || s2t-1==-1){
        printf("\nThe stack is full");
    }
    else{
        s1t++;
        printf("\nEnter the element : ");
        scanf("%d",&ar[s1t]);
        
    }

}
void pop1(){
    if(s1t==-1){
        printf("\nThe stack is empty");
    }
    else{
        if(s1t<=0){
            s1t=-1;
        }
        else{
            s1t--;
        }
    }
}
void push2(){
    if(s1t+1==s2t || s2t-1==-1||s1t+1==MAX){
        printf("\nThe stack is full");
    }
    else{
        if(s2t==-1)
            s2t=MAX-1;
        else
            s2t--;         
        printf("\nEnter the element : ");
        scanf("%d",&ar[s2t]);
    }
}
void pop2(){
    if(s2t==-1){
        printf("\nThe stack is empty");
    }
    else{
        if(s2t>=MAX){
            s2t=-1;
        }
        else{
            s2t++;
        }
    }
}            
void display(){
    int s1=s1t,s2=s2t;
   
    if(s1==-1){
        printf("\nstack 1 Empty");
    }
    else{
        printf("\nStack 1 : ");
        while(s1!=-1){
            printf("%d ",ar[s1]);
            s1--;
        }
    }
    if(s2==-1){
        printf("\nstack 2 Empty");
    }
    else{
        printf("\nStack 2 : ");
        while (s2!=MAX){
            printf("%d ",ar[s2]);
            s2++;
        }  
    }    
}
void main(){
    int o=1;
    while (o>0){
        printf("\n\nSelect an option\n1.stack 1 push\n2.stack 1 pop\n3.stack 2 push\n4.stack 2 pop\n5.Display\n6.exit\n");
        scanf("%d",&o);
        switch(o){
            case 1 :push1();
                    break;
            case 2 :pop1();
                    break;
            case 3 :push2();
                    break;
            case 4 :pop2();
                    break;
            case 5 :display();
                    break;
            case 6 :return;

        }
    
    }
    
  
}