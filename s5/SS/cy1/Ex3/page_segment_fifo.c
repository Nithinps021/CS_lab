#include<stdio.h>


int Check(int *ar,int size,int numb){
	int i;
	for(i=0;i<size;i++){
		if(ar[i]==numb){
			return 1;
		}
	}
	return 0;
}

void PagefaultCount(int *pages,int page_size,int capacity){
	int fifo[100],start=0,i,pageFault=0;
	for(i=0;i<page_size;i++){
		if(i<capacity){
			fifo[i]=pages[i];
			pageFault++;
		}
		else if(Check(fifo,capacity,pages[i])){
			continue;
		}
		else{
			if(start==capacity){
				start=0;
			}
			fifo[start]=pages[i];
			start++;
			pageFault++;
		}
	}
	printf("Number of page Fault : %d\n",pageFault );
}

void main(){
	int pages[100],capacity,i,page_size;
	printf("Enter total capacity and total pages\n");
	scanf("%d %d",&capacity,&page_size);
	printf("Enter the pages \n");
	for(i=0;i<page_size;i++){
		scanf("%d",&pages[i]);
	}
	PagefaultCount(pages,page_size,capacity);
}

/*

Enter total capacity and total pages
4 13
Enter the pages 
7 0 1 2 0 3 0 4 2 3 0 3 2
Number of page Fault : 7
*/