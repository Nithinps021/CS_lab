#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coef;
    int exp;
    struct node *next;
}node;

node* create(node* polyx,int terms){
    node *ptr;
    int i=1;
    while (terms--){
        if(polyx==NULL){
            ptr=polyx=(node*)malloc(sizeof(node));
        }
        else{
            ptr->next=(node*)malloc(sizeof(node));
            ptr=ptr->next;
        }
        printf("Enter the coefficent of %d term : ",i);
        scanf("%d",&(ptr->coef));
        printf("Enter the exponent of %d term : ",i);
        scanf("%d",&(ptr->exp));
        i++;
    }
    ptr->next=NULL;
    return polyx;
}

void display(node* polyx){
    int i=1;
    while(polyx!=NULL){
        if(i==1){      
            printf("%dx^%d ",polyx->coef,polyx->exp);
            polyx=polyx->next;
            i++;
        }
        else{
            if(polyx->coef==0){
                polyx=polyx->next;
                continue;
            }
            else if(polyx->exp==0){
                printf("+ %d",polyx->coef);
                polyx=polyx->next;
            }
            else{
                printf("+ %dx^%d ",polyx->coef,polyx->exp);
                polyx=polyx->next;
            }  
        }
    }
}

node* addition(node *poly,node *poly1,node *poly2){
    node *ptr,*ptrr=NULL;
    int i=1;
    while (poly1 && poly2){
        if(i==1){
            ptr=poly=(node*)malloc(sizeof(node));
            i++;
            ptr->next=NULL;
        }
        else{
            ptr->next=(node*)malloc(sizeof(node));
            ptr=ptr->next;
            ptr->next=NULL;
        }
        if(poly1->exp>poly2->exp){
            ptr->exp=poly1->exp;
            ptr->coef=poly1->coef;
            poly1=poly1->next;
        }
        else if(poly1->exp<poly2->exp){
            ptr->exp=poly2->exp;
            ptr->coef=poly2->coef;
            poly2=poly2->next;
        }
        else{
            ptr->coef=poly1->coef+poly2->coef;
            ptr->exp=poly1->exp;
            poly1=poly1->next;
            poly2=poly2->next;
        }      
    }
    if(poly2)
        ptrr=poly2;
    if(poly1)
        ptrr=poly1;
    while (ptrr){
        ptr->next=(node*)malloc(sizeof(node));
        ptr=ptr->next;
        ptr->next=NULL;
        ptr->coef=ptrr->coef;
        ptr->exp=ptrr->exp;
        ptrr=ptrr->next;
    }
    return poly;
} 



void main(){
    node *poly1=NULL,*poly2=NULL,*poly=NULL;
    int term;

    printf("\nEnter the number of terms in 1st polynomial : ");
    scanf("%d",&term);
    poly1=create(poly1,term);
    printf("\nEnter the number of terms in 2nd polynomial : ");
    scanf("%d",&term);
    poly2=create(poly2,term);

    printf("\nPolynomial 1 : ");
    display(poly1);
    printf("\nPolynomial 2 : ");
    display(poly2);
    printf("\npoly1 + poly2 = ");
    poly=addition(poly,poly1,poly2);
    display(poly);
    printf("\n");
}