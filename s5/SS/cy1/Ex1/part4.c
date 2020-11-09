#include<stdio.h>
#include<limits.h>

typedef struct process{
	int bt,at,wt,tt,ct,pr;
}
process;


void Priority(process *p, int n){
	int i,j,time=0,proc=-1;
	int priority=INT_MAX;
	int arrivalTime=INT_MAX;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(p[j].wt==-1){
				if(p[j].at<=time){
					if(proc==-1){
						priority=p[j].pr;
						arrivalTime=p[j].at;
						proc=j;
					}
					else if(p[j].pr<priority){
						priority=p[j].pr;
						arrivalTime=p[j].at;
						proc=j;
					}
					else if(p[j].pr==priority){
						if(p[j].at < arrivalTime){
							proc=j;
							arrivalTime=p[j].at;
						}
					}
				}
			}
		}
		if(proc==-1){
			time+=1;
			continue;
		}
		time+=p[proc].bt;
		p[proc].ct=time;
		p[proc].tt=p[proc].ct-p[proc].at;
		p[proc].wt=p[proc].tt-p[proc].bt;
		priority=INT_MAX;
		arrivalTime=INT_MAX;
		proc=-1;
	}


}


void main(){
	int n,i;
	process p[100];
	float avgTT=0,avgWT=0;
	printf("Enter no.of process \n");
	scanf("%d",&n);
	printf("Enter Arrival time , Burst time and priority\n");
	for(i=0;i<n;i++){
		scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].pr);
		p[i].wt=-1;
	}
	Priority(p,n);
	printf("P\tPT\tAT\tBT\tTT\tWT\n");


	for(i=0;i<n;i++){
		avgWT+=p[i].wt;
		avgTT+=p[i].tt;
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,p[i].pr,p[i].at,p[i].bt,p[i].tt,p[i].wt);
	}
	printf("Average Turn Around Time : %f\n",avgTT/n);
	printf("Average Waiting Time : %f\n",avgWT/n);
}

/*
Priority

Enter no.of process 
7
Enter Arrival time , Burst time and priority
0 8 3
1 2 4 
3 4 4
4 1 5
5 6 2
6 5 6
10 1 1
P       PT      AT      BT      TT      WT
1       3       0       8       8       0
2       4       1       2       16      14
3       4       3       4       18      14
4       5       4       1       18      17
5       2       5       6       9       3
6       6       6       5       21      16
7       1       10      1       5       4
Average Turn Around Time : 13.571428
Average Waiting Time : 9.714286

*/