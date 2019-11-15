#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}node;

void Graph(node *list[],int p1,int p2){
    node *ptr,*temp;
    ptr=(node*)malloc(sizeof(node));
    ptr->next=NULL;
    ptr->data=p2;
    if(list[p1]==NULL){
        list[p1]=ptr;
        return;
    }
    else{
        temp=list[p1];
        while (temp->next) {
            temp=temp->next;
        }
        temp->next=ptr;
    }
}
void DFS(node *list[],int start){
    int stack[100],top=0,*ar,p;
    node *ptr;
    ar=(int*)calloc(sizeof(int),100);
    stack[top]=start;
    top++;
    while (top!=0){
        p=stack[--top];
        if(ar[p]!=1){
            printf("%d ",p);
            ar[p]=1;
            ptr=list[p];
            while (ptr!=NULL){
                stack[top++]=ptr->data;
                ptr=ptr->next;
            }
        }   
    }
}
void BFS(node *list[],int start){
    int queue[100],l=0,r=0,*ar,p;
    node *ptr;
    ar=(int*)calloc(sizeof(int),100);
    queue[l]=start;
    r++;
    while(r!=l){
        p=queue[l++];
        if(ar[p]!=1){
            printf("%d ",p);
            ar[p]=1;
            ptr=list[p];
            while (ptr!=NULL){
                queue[r]=ptr->data;
                r++;
                ptr=ptr->next;
            }
        }
    }
}
void main(){
    int i,n,p1,p2,start;
    node *list[100];
    for(i=0;i<100;i++){
        list[i]=NULL;
    }
    printf("\nEnter the number of relation : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nRelation : ");
        scanf("%d %d",&p1,&p2); //showing edge from node p1 to node p2
        Graph(list,p1,p2);
    }
    printf("\nEnter the starting element : ");
    scanf("%d",&start);
    printf("\nDFS : ");
    DFS(list,start);
    printf("\nBFS : ");
    BFS(list,start); 
}