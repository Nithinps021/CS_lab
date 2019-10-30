#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *llink,*flink;
}node;

int search(node *root,int data){
    if(root==NULL){
        return 0;
    }
    else if(data<root->data){
        search(root->llink,data);
    }
    else if(data>root->data){
        search(root->flink,data);
    }
    else{
        return 1;
    }
}
node* insert(node* root,int data){
    node *ptr;
    if (search(root,data)){
        printf("\nThe element already exist.Input another element");
        scanf("%d",&data);
    }
    if(root==NULL){
        ptr=(node*)malloc(sizeof(node));
        ptr->data=data;
        ptr->flink=ptr->llink=NULL;
        return ptr;
    }
    else if(data<root->data){
        root->llink=insert(root->llink,data);
    }
    else if(data>root->data){
        root->flink=insert(root->flink,data);
    }
}
void inorder(node *ptr){
    if(ptr==NULL)
        return;
    else{
        inorder(ptr->llink);
        printf(" %d ",ptr->data);
        inorder(ptr->flink);
    }    
}
int max(node *root){
    if(root==NULL){
        printf("\nNo Elements in the tree");
        return -1;
    }
    else{
        if(root->flink==NULL){
            return root->data;
        }
        else{
            return max(root->flink);
        }
    }
}
node* delete(node *root, int data){
    node *ptr;
    int ele;
    if(root->data>data)
        root->llink=delete(root->llink,data);
    else if(root->data<data)
        root->flink=delete(root->flink,data);
    else{
        if(root->llink==NULL && root->flink==NULL){
            free(root);
            return NULL;
        }
        else if(root->llink==NULL){
            ptr=root->flink;
            free(root);
            return ptr;
        }
        else if(root->flink==NULL){
            ptr=root->llink;
            free(root);
            return ptr;
        }
        else{
            ele=max(root->llink);
            printf("print %d",ele);
            root->llink=delete(root->llink,ele);
            root->data=ele;
        } 
    }
    return root;
}
void main(){
    int o=1,data;
    node *root=NULL,ptr;
    do{
        printf("\n1.Insertion\n2.Display\n3.Search\n4.Delete\n5.Exit\nSelect an option ");
        scanf("%d",&o);
        if(o==1){
            printf("\nEnter the data : ");
            scanf("%d",&data);
            root=insert(root,data);
        }
        else if(o==2){
            inorder(root);
        }
        else if(o==3){
            printf("\nEnter the element to search : ");
            scanf("%d",&data);
            data=search(root,data);
            if(data)
                printf("\nThe element found !!");
            else 
                printf("\nThe element not found !!");
        }
        else if(o==4){
            printf("\nthe number to delete : ");
            scanf("%d",&data);
            root=delete(root,data);
        }
        else if(o==5)
            o=0;
    } while (o>=1);
    
}