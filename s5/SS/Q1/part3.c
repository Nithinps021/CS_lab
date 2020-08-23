#include<stdio.h>
#include<limits.h>

typedef struct process{
	int bt,wt,tt,ct,btc;
}
process;

void RoundRobin(process *p,int n){
	int flag=1,i,time=0;

	while(1){
		flag=1;
		for(i=0;i<n;i++){
			if(p[i].btc>0){
				flag=0;
				if(p[i].btc > 2){
					time+=2;
					p[i].btc=p[i].btc-2;
				}
				else if(p[i].btc<=2){
					time+=p[i].btc;
					p[i].btc=0;
					p[i].ct=time;
					p[i].wt=time -p[i].bt;
					p[i].tt=p[i].wt + p[i].bt;
				}
			}
			
		}

		if(flag){
			break;
		}
	}
}


void main(){
	int n,i;
	process p[100];
	float avgTT=0,avgWT=0;
	printf("Enter no.of process \n");
	scanf("%d",&n);
	printf("Enter Burst time\n");
	for(i=0;i<n;i++){
		scanf("%d",&p[i].bt);
		p[i].btc=p[i].bt;
	}
	RoundRobin(p,n);
	printf("P\tBT\tTT\tWT\n");
	for(i=0;i<n;i++){
		avgWT+=p[i].wt;
		avgTT+=p[i].tt;
		printf("%d\t%d\t%d\t%d\n",i+1,p[i].bt,p[i].tt,p[i].wt);
	}
	printf("Average Turn Around Time : %f\n",avgTT/n);
	printf("Average Waiting Time : %f\n",avgWT/n);
}