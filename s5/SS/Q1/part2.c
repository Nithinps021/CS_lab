#include<stdio.h>
#include<limits.h>

typedef struct process{
	int bt,at,wt,tt,ct;
}
process;


void ShortestJobFirst(process *p, int n){
	int i,j,time=0,proc=-1;
	int burstTime=INT_MAX;
	int arrivalTime=INT_MAX;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(p[j].wt==-1){
				if(p[j].at<=time){
					if(proc==-1){
						burstTime=p[j].bt;
						arrivalTime=p[j].at;
						proc=j;
					}
					else if(p[j].bt<burstTime){
						burstTime=p[j].bt;
						arrivalTime=p[j].at;
						proc=j;
					}
					else if(p[j].bt==burstTime){
						if(p[j].at < arrivalTime){
							proc=j;
							arrivalTime=p[j].at;
						}
					}
				}
			}
		}
		time+=p[proc].bt;
		p[proc].ct=time;
		p[proc].tt=p[proc].ct-p[proc].at;
		p[proc].wt=p[proc].tt-p[proc].bt;
		burstTime=INT_MAX;
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
	printf("Enter Arrival time and Burst time\n");
	for(i=0;i<n;i++){
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].wt=-1;
	}
	ShortestJobFirst(p,n);
	printf("P\tAT\tBT\tTT\tWT\n");
	for(i=0;i<n;i++){
		avgWT+=p[i].wt;
		avgTT+=p[i].tt;
		printf("%d\t%d\t%d\t%d\t%d\n",i+1,p[i].at,p[i].bt,p[i].tt,p[i].wt);
		
	}
	printf("Average Turn Around Time : %f\n",avgTT/n);
	printf("Average Waiting Time : %f\n",avgWT/n);
}