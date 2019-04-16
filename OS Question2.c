#include<conio.h>
#include<stdio.h>
int main()
{
	int last = 4999; // Total cylinders are 5000 so last location will be 4999
	int move=0;
	int n;  //Number of pending requests in queue 
	int current; //Current location of disk
	printf("\nEnter number of pending request in queue\t");
 	scanf("%d",&n);
 	int queue[n]; //Elements of disk queue of size n
 	printf("\nEnter position of current disk\t");
 	scanf("%d",&current);
 	printf("\nEnter elements of disk queue\n");
 	int i,temp,j;
 	for(i=0;i<n;i++) // Input elements
	{
	printf("\nEnter element %d\n",i+1);
 	scanf("%d",&queue[i]);
 	}
 	queue[n]=current;
 	n=n+1;
 	for(i=0;i<n;i++)    // Sorting disk 
 	{
  		for(j=i;j<n;j++)
  			{
    			if(queue[i]>queue[j])
    			{
    				temp=queue[i];
    				queue[i]=queue[j];
    				queue[j]=temp;
    			}
  			}
 	}
 	int first= queue[0];
 	
 	for(i=0;i<n;i++) 
	{
 		if(queue[i]>current)
 		{
		 	move = move + (queue[i]-current);
			current = queue[i];	
		}
		if(i == n-1)
		{
			move = move +(last - current);
			current = last;
		}
 	}
 	
 	move= move + (last - first);

 	printf(" \n\n\nTotal movements required %d",move);
 	getch();
}

