#include<stdio.h>



typedef struct process{
	int at,bt,tt,wt;
}
process;


void findingTTandWT(process *p,int n){
	int ct=0,i;
	for(i=0;i<n;i++){
		ct+=p[i].bt;
		p[i].tt=ct-p[i].at;
		p[i].wt=p[i].tt -p[i].bt;
	}
}


void main(){
	process p[100];
	int n,i=0;
	float avgTT=0,avgWT=0;
	printf("Enter the number of process needed : \n");
	scanf("%d",&n);
	printf("Enter arrival time and burst time\n");
	for(i=0;i<n;i++){
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].tt=0;
		p[i].wt=0;
	}
	findingTTandWT(p,n);
	printf("P   TT   WT\n");
	for(i=0;i<n;i++){
		avgWT+=p[i].wt;
		avgTT+=p[i].tt;
		printf("P%d   %d   %d\n",i,p[i].tt,p[i].wt);
		
	}
	printf("Average Turn Around Time : %f\n",avgTT/n);
	printf("Average Waiting Time : %f\n",avgWT/n);
}

/*
OUTPUT FCFS

Enter the number of process needed : 
3
Enter arrival time and burst time
0 5
3 9
6 6
P   TT   WT
P0   5   0
P1   11   2
P2   14   8
Average Turn Around Time : 10.000000
Average Waiting Time : 3.333333
*/