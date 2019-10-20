#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 6

int stack[MAX],sf=-1;

void prefix(char *ar){
    int n=strlen(ar),a,b;
    while(n>=0){
        n--;
        if(ar[n]>='0'&& ar[n]<='9'){
            sf++;
            stack[sf]=ar[n]-48;
            printf("%d",stack[sf]);
        }
        else{
            switch(ar[n]){
                case '+':a=stack[sf];
                         b=stack[--sf];
                         stack[sf]=b+a;
                         break;
                case '-':a=stack[sf];
                         b=stack[--sf];
                         stack[sf]=a-b;
                         break;
                case '*':a=stack[sf];
                         b=stack[--sf];
                         stack[sf]=a*b;
                         break;
                case '/':a=stack[sf];
                         b=stack[--sf];
                         stack[sf]=a/b;
                         break;                           
            }
        } 
    }
    printf("\nanswer : %d",stack[0]);
}

void postfix(char *ar){
    int n=0,a,b;
    while(ar[n]!='\0'){
        if(ar[n]>='0'&& ar[n]<='9'){
            sf++;
            stack[sf]=ar[n]-48;
            printf("%d",stack[sf]);
        }
        else{
            switch(ar[n]){
                case '+':a=stack[sf];
                         b=stack[--sf];
                         stack[sf]=b+a;
                         break;
                case '-':a=stack[sf];
                         b=stack[--sf];
                         stack[sf]=b-a;
                         break;
                case '*':a=stack[sf];
                         b=stack[--sf];
                         stack[sf]=a*b;
                         break;
                case '/':a=stack[sf];
                         b=stack[--sf];
                         stack[sf]=b/a;
                         break;                           
            }
        }
        n++; 
    }
    printf("\nanswer : %d",stack[0]);
}

void main(){
    char exp[MAX];
    int o=1;
    while (o>0){
        printf("\n\nSelect an option\n1.evaluvation prefix\n2.evaluvation of postfix\n3.EXIT");
        scanf("%d",&o);

        if(o==1){
            sf=-1;
           printf("\nEnter the string : ");
           scanf("%s",exp);
           prefix(exp); 
        }
        else if(o==2){
           sf=-1;
           printf("\nEnter the string : ");
           scanf("%s",exp);
           postfix(exp); 
        }
        else{
            return;
        }        
           
    }
    


}