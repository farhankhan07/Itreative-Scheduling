#include<stdio.h>
int main()
{
	int n,i,count,t,flag=0;
	printf("\n Enter Number of processes ::");
	scanf("%d",&n);
	int exect[n],Arrival_Time[n],TimeQuantum=3,Proc[n],tat=0,wt=0,rt[n],r=n;
	for(i=0;i<n;i++)
	
	{
		
		Proc[i]=i;
		printf("\nEnter Arrival Time of Process %d :: ",i+1);
		scanf("%d",&Arrival_Time[i]);
		printf("Enter Burst Time of Process %d ::",i+1);
		scanf("%d",&exect[i]);
		rt[i]=exect[i];
	}
	
	printf("\nProcess\t Turnaround Time Waiting Time\n");
	for(t=0,count=0;r!=0;)
	
	{
		
		if(rt[count]<=TimeQuantum&&rt[count]>0)
		
		{
			
			t=t+rt[count];
			rt[count]=0;
			flag=1;
			
		}
		
		else if(rt[count]>0)
		
		{
			
		rt[count]-=TimeQuantum;
		t=t+TimeQuantum;
		
		}
		
		if(rt[count]==0&&flag==1)
		
		{
			
		r--;
		printf("P[%d]\t|\t%d\t|\t%d\n",count+1,t-Arrival_Time[count],t-Arrival_Time[count]-exect[count]);
		wt+=t-Arrival_Time[count]-exect[count];
		tat+=t-Arrival_Time[count];
		flag=0;
		
		}
		
		if(count==n-1)
		count=0;
		else if(Arrival_Time[count+1]<=t)
		count++;
		else
		count=0;
	}
	
printf("\nAverage WT= %f\n",wt*1.0/n);
printf("Avg TAT = %f",tat*1.0/n);

}
