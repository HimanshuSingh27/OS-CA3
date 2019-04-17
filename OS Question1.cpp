#include<stdio.h> 
int main() 
{ 
      int p;       
	  int lim;       
	  int total_t = 0;       
	  int x;       
	  int counter_c = 0;       
	  int timeQuantum;       
	  int turnAroundTime=0;       
	  int waitingTime=0;       
	  int arrivalTime[10];       
	  int burstTime[10]; 
      int tempBurst[10],priorityArray[10];       
	  float avg_WaitingTime, avg_TurnAroundTime;       
	  printf("\t\tRound Robin Scheduling algorithm with Higher number priority and preemption\t");         
	  printf("\nEnter total  Number of Processes to be scheduled:\t");       
	  scanf("%d", &lim); 
      x = lim; 
      for(p = 0; p < lim; p++) 
      { 
            printf("\nEnter following details of Process[%d]\n", p + 1);             
			printf("Arrival Time of Process  :\t");             
			scanf("%d", &arrivalTime[p]);             
			printf("Burst Time of Process  :\t");             
			scanf("%d", &burstTime[p]);             
			printf("priority of Process  :\t");             
			scanf("%d",&priorityArray[p]); 
 	 
      } 
}
