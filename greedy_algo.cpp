#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	void swap(int *a,int *b)
	{
		int temp=*a;
		*a=*b;
		*b=temp;
	}
	
int main()
{
	int n;


	printf("Enter number of jobs :");
	scanf("%d",&n);
	int profit[50];
	int deadline[50];
	char name[n][10];

	for(int i=0;i<n;i++)
	{
	  sprintf(name[i],"job%d",+i+1);
	}
	for (int i = 0; i < n; i++) {
        printf("Job %d: %s\n", i+1, name[i]);
    }
	for(int i=0;i<n;i++){
	
	 printf("\n Enter profit for %s : ",name[i]);
	 scanf("%d",&profit[i]);
}
	for(int i=0;i<n;i++){
	
	 printf("\n Enter deadline for %s : ",name[i]);
	 scanf("%d",&deadline[i]);
}
    

		for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                swap(&profit[j], &profit[j + 1]);
                 swap(&deadline[j], &deadline[j + 1]);
                 char temp[10];
                strcpy(temp, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], temp);
            }
        }
    }
	
		
	
    printf("\n\nHighest profits:\n");
	printf("|JOBS");
    for (int i = 0; i < n; i++) {
    	printf("|%s|",name[i]);

    }
    	printf("\n|PROFIT");
    	 for (int i = 0; i < n; i++) {
    	printf("|%d|",profit[i]);

    }
    	printf("\n|DEADLINE");
    	 for (int i = 0; i < n; i++) {
    	printf("|%d|",deadline[i]);

    }
    int max_deadline=0;
  	for(int i=0;i<n;i++)
	  {
		if(max_deadline<deadline[i])
		{
			max_deadline=deadline[i];	
		}	
	  }
    
   printf("\n max deadline is: %d \n",max_deadline);
  
    printf("\nJob Schedule:\n");

    int schedule[max_deadline];

    for (int i = 0; i < max_deadline; i++) {
        schedule[i] = -1; 
    }
 int total_profit = 0;
    for (int i = 0; i < n; i++) {
        int current_deadline = deadline[i];
        while (current_deadline > 0) {
            if (schedule[current_deadline - 1] == -1) {
                schedule[current_deadline - 1] = i;
                total_profit += profit[i];
                break;
            }
            current_deadline--;
        }
    }

    for (int i = 0; i < max_deadline; i++) {
        printf("Time Slot %d: ", i + 1);
        if (schedule[i] != -1) {
            printf("%s", name[schedule[i]]);
        } else {
            printf("Empty Slot");
        }
        printf("\n");
    }
    printf("Maximum Profit: %d\n", total_profit);
 

    return 0;
}
