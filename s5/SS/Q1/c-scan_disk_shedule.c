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
	int i;
	*sleek+=abs(0-*head);
	*head=0;
	for(i=0;ar[i]<head_org;i++){
		*sleek+=abs(ar[i]-*head);
		*head=ar[i];
	}
}
void Right(int *ar,int n,int *head,int head_org, int *sleek){
	int i;
	for(i=0;i<n;i++){
		if(ar[i]<head_org){
			continue;
		}
		else{
			*sleek+=abs(ar[i]-*head);
			*head=ar[i];
		}
	}

	*sleek+=abs(199-*head);
	*head=199;

	
	
}
void Scan(int *ar,int n,int head){
	int sleek_count=0,head_org=head;
	Right(ar,n,&head,head_org,&sleek_count);
	Left(ar,n,&head,head_org,&sleek_count);
	printf("Sleek count: %d\n",sleek_count);
}

void main(){
	int n,i,arr[100],head;
	printf("Enter Head and length of sequence \n");
	scanf("%d %d",&head,&n);
	printf("Enter the sequence\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,n);
	
	Scan(arr,n,head);
}