#include<stdio.h>

int abs(int n){
	if(n<0){
		return -1*n;
	}
	else{
		return n;
	}
}


void FCFS(int *arr,int n,int head){
	int seek_count=0,i,dis;
	for(i=0;i<n;i++){
		dis=abs(arr[i]-head);
		seek_count+=dis;
		head=arr[i];
	}
	printf("Number of seek operations : %d \n",seek_count );
}

void main(){
	int n,i,arr[100],head;
	printf("Enter Head and length of sequence \n");
	scanf("%d %d",&head,&n);
	printf("Enter the sequence\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	FCFS(arr,n,head);
}


/*
Enter Head and length of sequence 
50 8
Enter the sequence
176 79 34 60 92 11 41 114
Number of seek operations : 510 
*/