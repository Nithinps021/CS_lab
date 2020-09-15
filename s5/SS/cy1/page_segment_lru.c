#include<stdio.h>
#include<limits.h>


int Check(int *ar,int size,int numb){
	int i;
	for(i=0;i<size;i++){
		if(ar[i]==numb){
			return 1;
		}
	}
	return 0;
}

int leastRecentlyused(int *index,int *lru,int c){
	int i,min=0;
	for(i=0;i<c;i++){
		if(index[lru[i]]<index[lru[min]]){
			min=i;
		}
	}
	index[lru[min]]=INT_MAX;
	return min; 
}

void PagefaultCount(int *pages,int page_size,int capacity){
	int lru[100],i,pageFault=0,lru_index[100],index;
	for(i=0;i<100;i++){
		lru_index[i]=INT_MAX;
	}
	for(i=0;i<page_size;i++){
		if(i<capacity){
			lru[i]=pages[i];
			pageFault++;
			lru_index[pages[i]]=i;
		}
		else if(Check(lru,capacity,pages[i])){
			lru_index[pages[i]]=i;
			continue;
		}
		else{
			lru_index[pages[i]]=i;
			index=leastRecentlyused(lru_index,lru,capacity);
			lru[index]=pages[i];
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