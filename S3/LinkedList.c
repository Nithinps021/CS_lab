#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
  
}node;

void Display(node *head){
    node *ptr=head;
    if(head==NULL){
        printf("\nThe list is empty!!");
    }
    while (ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
} 

node* i_front(node *head){
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    printf("Enter the data : ");
    scanf("%d",&(ptr->data));
    if(head== NULL){
        ptr->link=NULL;
        return ptr;
    }
    else{
        ptr->link=head;
        return ptr;
    }
}

node* d_front(node *head){
    if(head==NULL){
        printf("\nThe list is empty!!");
        return NULL;
    }
    else{
        head=head->link;
        return head;
    }
}

node* i_tail(node *head){
    node *ptr=head,*temp;
    if(head==NULL){
        ptr=(node*)malloc(sizeof(node));
        printf("Enter the data : ");
        scanf("%d",&(ptr->data));
        ptr->link=NULL;
        return ptr;
    }
    else{
        while (ptr->link!=NULL){
            ptr=ptr->link;
        }
        temp=(node*)malloc(sizeof(node));
        temp->link=NULL;
        printf("Enter the Data : ");
        scanf("%d",&(temp->data));
        ptr->link=temp;
        return head;
    }    
}

node* d_tail(node *head){
    node *ptr=head;
    if(head==NULL){
        printf("\nThe list is empty!!");
        return NULL;
    }
    else if(head->link==NULL){
        return NULL;
    }
    else{
        while ((ptr->link)->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=NULL;
        return head;
    }
    
}

node* i_at_pos(node *head){
    node *ptr,*temp=head;
    int pos,i;
    ptr=(node*)malloc(sizeof(node));
    printf("Enter the position : ");
    scanf("%d",&pos);
    printf("Enter the data: ");
    scanf("%d",&(ptr->data));
    for(i=1;i<pos-1;i++){
        temp=temp->link;
    }
    if(pos==1){
        ptr->link=head;
        return ptr;
    }
    else{
        ptr->link=temp->link;
        temp->link=ptr;
        return head; 
    }
}

node* d_at_pos(node *head){
    node *ptr=head;
    int pos,i;
    printf("Enter the position : ");
    scanf("%d",&pos);
    for(i=1;i<pos-1;i++){
        ptr=ptr->link;
    }
    if(pos==1){
        head=head->link;
        return head;
    }
    else{
        ptr->link=(ptr->link)->link;
        return head;
    }
}

void main(){
    node *head=NULL;
    int o=1;
    while (o<7){
        printf("\nSELECET AN OPTION \n1.Insertion In Front\n2.Deletion From Front\n3.Insertion In Tail\n4.Deletion From Tail\n5.Insert at a position\n6.Delete froma a position\n7.EXIT\n"); 
        scanf("%d",&o);
        switch(o){
            case 1:head=i_front(head);
                    Display(head);
                    break;
            case 2:head=d_front(head);
                    Display(head);
                    break;
            case 3:head=i_tail(head);
                    Display(head);
                    break;
            case 4:head=d_tail(head);
                    Display(head);
                    break;
            case 5:head=i_at_pos(head);
                    Display(head);
                    break;                                
            case 6:head=d_at_pos(head);
                    Display(head);
                    break;             
        }
    }
}
