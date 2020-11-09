#include <stdio.h>

int abs(int n){
	if(n<0){
		return -1*n;
	}
	else{
		return n;
	}
}
void sort(int *ar,int n){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(ar[j]>ar[j+1]){
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}
}
void Left(int *ar,int n,int *head,int head_org, int *sleek){
	int i,initial=*sleek;
	for(i=n-1;i>-1;i--){
		if(ar[i]>head_org){
			continue;
		}
		else{
			*sleek+=abs(ar[i]-*head);
			*head=ar[i];
		}
	}
	if(initial==0){
		*sleek+=abs(0-*head);
		*head=0;
	}

	
}
void Right(int *ar,int n,int *head,int head_org, int *sleek){
	int i,initial=*sleek;;
	for(i=0;i<n;i++){
		if(ar[i]<head_org){
			continue;
		}
		else{
			*sleek+=abs(ar[i]-*head);
			*head=ar[i];
		}
	}
	if(initial==0){
		*sleek+=abs(200-*head);
		*head=200;
	}
	
	
}
void Scan(int *ar,int n,int head,int pos){
	int sleek_count=0,head_org=head;
	if(pos==1){
		Right(ar,n,&head,head_org,&sleek_count);
		Left(ar,n,&head,head_org,&sleek_count);
	}
	else{
		Left(ar,n,&head,head_org,&sleek_count);
		Right(ar,n,&head,head_org,&sleek_count);
	}
	printf("Sleek count: %d\n",sleek_count);
}

void main(){
	int n,i,arr[100],head,pos;
	printf("Enter Head and length of sequence \n");
	scanf("%d %d",&head,&n);
	printf("Enter the sequence\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,n);
	printf("direction Right(1) Left(-1): \n");
	scanf("%d",&pos);
	Scan(arr,n,head,pos);
}

/*
Enter Head and length of sequence 
50 8 
Enter the sequence
176 79 34 60 92 11 41 114
direction Right(1) Left(-1): 
-1
Sleek count: 226
*/