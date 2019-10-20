#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

char stack[MAX];
int sf=0;

char posfix[MAX];
int pos=0;

int precedence(char a){
    switch (a){
        case '-':
        case '+':return 1;
        case '*':
        case '/':return 4;
    }
}

void main(){
    char exp[MAX];
    int i=0;
    printf("\nGive an expression : ");
    scanf("%s",exp);

    while(exp[i]!='\0'){
        if(exp[i]>='a' && exp[i]<='z'){
            posfix[pos]=exp[i];
            i++;
            pos++;
        }
        else{
            if(sf==-1){
                sf++;
                stack[sf]=exp[i];
            }
            else if(precedence(exp[i])>=precedence(stack[sf])){
                sf++;
                stack[sf]=exp[i];
            }
            else if(precedence(exp[i])<precedence(stack[sf])){
                while(precedence(exp[i])<precedence(stack[sf])){
                    posfix[pos]=stack[sf];
                    sf--;
                    pos++;
                }
                stack[++sf]=exp[i];
            }
            i++;      
        }   
    }
    while(sf!=-1){
        posfix[pos]=stack[sf];
        --sf;
        ++pos;
    }
    posfix[pos]='\0';
    printf("\nThe posfix expression is : %s\n",posfix);

    
}
