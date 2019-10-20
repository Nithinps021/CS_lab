#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int data;
    struct stack *link;
}stack;

stack* push(stack* head){
    stack *ptr;
    ptr=(stack*)malloc(sizeof(stack));
    printf("\nEnter the data : ");
    scanf("%d",&(ptr->data));
    ptr->link=NULL;
    if(head==NULL){
        return ptr;
    }
    else{
        ptr->link=head;
        return ptr;
    }
}

stack* pop(stack *head){
    if (head==NULL){
        return NULL;
    }
    else{
        return head->link;
    }
}
void display(stack *head){
    if(head!=NULL){
        printf("The stack is :");
        while(head!=NULL){
            printf("%d ",head->data);
            head=head->link;
        }
    }
    else{
        printf("\nStack is Empty");
    }
} 

void main(){
    int o=1;
    stack *head=NULL;
    while (o>0 && o<4){
        printf("\n\n1.PUSH\n2.POP\n3.Exit\nSelect an Option : ");
        scanf("%d",&o);
        if (o==1){
            head=push(head);
            display(head);
        }
        else if(o==2){
            head=pop(head);
            display(head);
        }
        else{
            return; 
        }
    }
}