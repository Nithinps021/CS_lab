#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coef;
    int exp;
    struct node *next;
}node;

node* create(node* polyx,int terms){ //for creating polynomial expression 
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

void display(node* polyx){    //displaying polynomial
    int i=1;
    while(polyx!=NULL){
        if(i==1){
            if(polyx->coef==0){
                polyx=polyx->next;
                continue;
            }
            else{
                printf("%dx^%d ",polyx->coef,polyx->exp);
                polyx=polyx->next;
                i++;
            }      
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

node* addition(node *poly,node *poly1,node *poly2){ //adding two polynomial expression
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

node* filter(node* poly){ // for eliminating terms having same power.
    node *ptr1=poly,*ptr2;
    while(ptr1){
        ptr2=ptr1;
        while(ptr2->next!=NULL){
            if(ptr1->exp==ptr2->next->exp){
                ptr1->coef=ptr1->coef+ptr2->next->coef;
                ptr2->next=ptr2->next->next;
            }
            else{
                ptr2=ptr2->next;
            }       
        }
        ptr1=ptr1->next;
    }
    return poly;
}

node* multiply(node *poly,node *poly1,node *poly2){ //multiplying two polynomials
    node *ptr1=poly1,*ptr2,*ptr;
    int i=1;
    while(ptr1){
        ptr2=poly2;
        while (ptr2){
            if(i==1){
                ptr=poly=(node*)malloc(sizeof(node));
                ptr->next=NULL;
                i++;
            }
            else{
                ptr->next=(node*)malloc(sizeof(node));
                ptr=ptr->next;
                ptr->next=NULL;
            }
            ptr->coef=ptr1->coef*ptr2->coef;
            ptr->exp=ptr1->exp+ptr2->exp;
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    poly=filter(poly);
    return poly;
}



void main(){
    node *poly1=NULL,*poly2=NULL,*poly=NULL;
    int term1,term2,o=1;

    while(o>0 && o<4){
        printf("\n\n1.Addition\n2.Multiplication\n3.Exit\nSelect an option : ");
        scanf("%d",&o);
        if(o==1){
            printf("\nEnter the number of terms in 1st polynomial : ");
            scanf("%d",&term1);
            poly1=create(poly1,term1);
            printf("\nEnter the number of terms in 2nd polynomial : ");
            scanf("%d",&term1);
            poly2=create(poly2,term1);
            printf("\nPolynomial 1 : ");
            display(poly1);
            printf("\nPolynomial 2 : ");
            display(poly2);
            printf("\npoly1 + poly2 = ");
            poly=addition(poly,poly1,poly2);
            display(poly);
        }
        else if (o==2){
            printf("\nEnter the number of terms in 1st polynomial : ");
            scanf("%d",&term2);
            poly1=create(poly1,term2);
            printf("\nEnter the number of terms in 2nd polynomial : ");
            scanf("%d",&term2);
            poly2=create(poly2,term2);
            printf("\nPolynomial 1 : ");
            display(poly1);
            printf("\nPolynomial 2 : ");
            display(poly2);
            printf("\npoly1 * poly2 = ");
            poly=multiply(poly,poly1,poly2);
            display(poly);
        }
        else{
            break;        
        }   
    }
    printf("\n");
}