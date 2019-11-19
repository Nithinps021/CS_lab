#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAX 101
typedef struct node{
    char name[10];
    char dob[12];
    int  rollno;
    struct  node *link;
}node;

int hash(char name[]){
    int sum=0,i,l;
    for(l=0;name[l]!='\0';l++){
        sum=sum+(int)name[l]*(l+1);
    }
    i=sum%MAX;
    return i;
}

int main(){
    int i,n,o=1;
    node *hashtable[MAX],*ptr,*temp;
    char name[10];
    for(i=0;i<101;i++){
        hashtable[i]=NULL;
    }
    printf("\nNumber of Students : ");
    scanf("%d",&n);
    while(n--){
        ptr=(node*)malloc(sizeof(node));
        ptr->link=NULL;
        printf("\nName Of Student   : ");
        scanf(" %s",ptr->name);
        printf("DOB(dd/mm/yyyy)   : ");
        scanf(" %[^\n]s",ptr->dob);
        printf("RollNo            : ");
        scanf("%d",&(ptr->rollno));
        i=hash(ptr->name);
        if(hashtable[i]==NULL){
            hashtable[i]=ptr;
        }
        else{
            temp=hashtable[i];
            while(temp->link){
                temp=temp->link;
            }
            temp->link=ptr;
        }
        printf("\n");
    }
    while(o){
        printf("\nName Of a student to Search : ");
        scanf(" %[^\n]s",name);
        i=hash(name);
        temp=hashtable[i];
        while(temp!=NULL){
            if(strcmp(temp->name,name)!=0)
                temp=temp->link;
            else
                break;
        }
        if(temp==NULL){
            printf("Sorry the Name NOT found !!");
        }
        else{
            printf("\nName            : %s",temp->name);
            printf("\nRollNo          : %d",temp->rollno);
            printf("\nDOB(dd/mm/yyyy) : %s",temp->dob);
        }
        printf("\n\nEnter 0 to exit or 1 to continue : ");
        scanf("%d",&o);
    }
    printf("\n");

}