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
      for(p=0;p<lim;p++) 
      {           
	  		int j; 
            for( j=p+1;j<lim;j++) 
            { 
                  int swap=priorityArray[p];                   
				  priorityArray[p]=priorityArray[j];                   
				  priorityArray[j]=swap; 
              } 
              tempBurst[p]=burstTime[p]; 
        } 
        printf("\nEnter Time Quantum for the process:\t");       
		scanf("%d", &timeQuantum);       
		printf("\nProcess__ID\t\tArrival__Time\tBurst__Time\t TurnAround__Time\t Waiting__Time\n");       
		for(total_t = 0, p = 0; x != 0;) 
      { 
            if(tempBurst[p] <= timeQuantum && tempBurst[p] > 0) //time on every preemption 
            { 
                  total_t = total_t + tempBurst[p];                   
				  tempBurst[p] = 0;                   
				  counter_c = 1; 
            } 
            else if(tempBurst[p] > 0)  
            { 
                  tempBurst[p] = tempBurst[p] - timeQuantum;                   
				  total_t = total_t + timeQuantum; 
            } 
            if(tempBurst[p] == 0 && counter_c == 1) 
            {                   
					x--; 
                    turnAroundTime=total_t-arrivalTime[p];                   
					waitingTime=turnAroundTime-burstTime[p];                   
					if(turnAroundTime<0) 
                		{ 
                          turnAroundTime=0; 
                  		}                           
					if(waitingTime<0) 
                		{                           
						 waitingTime=0; 
                  		} 
                printf("\nProcess[%d]\t\t%d\t\t%d\t\t %d\t\t\t %d", p + 1,arrivalTime[p], burstTime[p], turnAroundTime, waitingTime); 	 
                  turnAroundTime=turnAroundTime+total_t-arrivalTime[p];                   
				  waitingTime=waitingTime+total_t-arrivalTime[p]-burstTime[p];                   
				  if(waitingTime<0) 
                 		{                                
						 waitingTime=0; 
                 		} 
                          counter_c = 0; 
            } 
            if(p == lim - 1) 
            {                   
				p = 0; 
            } 
            else if(arrivalTime[p + 1] <= total_t) //process in queue 
            {                   
				p++; 
            }             
			else             
			{                   
				p = 0; 
            } 
      } 
      avg_WaitingTime = waitingTime * 1.0 / lim; 
      avg_TurnAroundTime = turnAroundTime * 1.0 / lim;       
	  printf("\n\nAverage__Waiting__Time:\t%0.2f", avg_WaitingTime);       
	  printf("\nAvg__Turnaround__Time:\t%0.2f\n", avg_TurnAroundTime);       
	  return 0; 
} 
