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

int position(int *ar,int len,int n){
	int i;
	for(i=0;i<len;i++){
		if(n==ar[i]){
			return i;
		}
	}
}

int leastFrequentlyUsed(int *count,int *lfu,int capacity,int *pages,int page_size){
	int i,min=0;
	for(i=1;i<capacity;i++){
		if(count[lfu[i]]>0){
				if(count[lfu[i]]<count[lfu[min]]){
				min=1;
			}
			else if(count[lfu[i]]==count[lfu[min]]){
				if(position(pages,page_size,lfu[i])<position(pages,page_size,lfu[min])){
					min=i;
				}
			}
		}
	}
	count[pages[min]]--;
	return min; 
}

void PagefaultCount(int *pages,int page_size,int capacity){
	int lfu[100],i,pageFault=0,count_index[100],index;
	for(i=0;i<100;i++){
		count_index[i]=0;
	}
	for(i=0;i<page_size;i++){
		count_index[pages[i]]++;
		if(i<capacity){
			lfu[i]=pages[i];
			pageFault++;
		}
		else if(Check(lfu,capacity,pages[i])){
			continue;
		}
		else{
			index=leastFrequentlyUsed(count_index,lfu,capacity,pages,page_size);
			lfu[index]=pages[i];
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
3 12
Enter the pages 
1 2 3 4 5 2 5 2 5 1 4 3
Number of page Fault : 9

*/