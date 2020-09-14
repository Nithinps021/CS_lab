#include<stdio.h>



void arrayFill(int ar[100][100],int p,int r){
    int i,j;
    for(i=0;i<r;i++){
        printf("\tR%d\t",i);
    }
    printf("\n");
    for(i=0;i<p;i++){
        printf("P%d\t",i);
        for(j=0;j<r;j++){
            scanf("%d",&ar[i][j]);
        }
    }
}
void print2d(int *ar[100],int p,int r){
    int i,j;
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            printf("%d\t",ar[i][j]);
        }
        printf("\n");
    } 
}
void arrayfill1D(int *ar,int r){
    int i;
    for(i=0;i<r;i++){
        printf("R%d\t ",i);
    }
    printf("\n");
    for(i=0;i<r;i++){
        scanf("%d",&ar[i]);
    }
}
void needArray(int max[100][100],int all[100][100],int need[100][100],int p,int r){
    int i,j;
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            need[i][j]=max[i][j]-all[i][j];
        }
    }
}

void safeSequence(int need[100][100],int *available,int p,int r,int *sequence){
    int count=0,flag[100],i,pass,j;
    for(i=0;i<100;i++){
        flag[i]=0;
    }
    while(count!=p){
        printf("%d\n",count);
        for(i=0;i<p;i++){
            pass=1;
            if(flag[i]==0){
                for(j=0;j<r;j++){
                    if(need[i][j]>available[j]){    
                        pass=0;
                        break;
                    }
                }
                if(pass){
                    for(j=0;j<r;j++){
                        available[j]+=need[i][j];
                    }
                    sequence[count]=i;
                    count++;
                    flag[i]=1;
                }
            }
        }
    }
}

void main(){
 int avilable[100],max[100][100],allocated[100][100],need[100][100],seq[100];
 int p,r,i;
 printf("\n");
 printf("Enter total process and resources\n");
 scanf("%d %d",&p,&r);
 printf("\n");
 printf("Enter maximum resources\n");
 arrayFill(max,p,r);
 printf("\n");
 printf("Enter allocated resources\n");
 arrayFill(allocated,p,r);
 printf("\n");
 printf("Enter the available resources\n");
 arrayfill1D(avilable,r);
 needArray(max,allocated,need,p,r);
 safeSequence(need,avilable,p,r,seq);
 printf("\n");
 for(i=0;i<p-1;i++){
     printf("P%d -> ",seq[i]);
 }
 printf("p%d\n",seq[i]);
 printf("\n");
}