#include<stdio.h>
#include<stdlib.h>
	void swap(int *a,int *b)
	{
		int temp=*a;
		*a=*b;
		*b=temp;
	}
	
	
int partition(int ar[],int low,int high)
{ int pivot=low;
		while(low<=high)
	{
	     if(ar[high]>=ar[pivot])
		{
		high--;	
		}
		 else if(ar[low]<=ar[pivot])
		{
			low++;	
		}
	     
		if(low>high)
		{	
		  	swap(&high,&pivot);
			swap(&ar[high],&ar[pivot]);
	 
		}
		
		else if((ar[low]>ar[pivot])&& (ar[high]<ar[pivot]))
		{
			swap(&ar[low],&ar[high]);
			
			
		}
	
	} 
	return pivot;
	

}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
    	
        int pi = partition(arr, low, high);
        printf("\n %d",pi);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{
	int n;
	printf("enter number of element in array:");
	scanf("%d",&n);
	printf("\n enter elements in array:");
	
	int *arr=(int *)malloc(n*sizeof(int));
	
	
	for(int i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);	
	}
	

	printf("\n element in array are pahile:");
	for(int i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
int low=0;
int high=n-1;

quickSort(arr,low,high);

	
	printf("\n element in array are nantr:");
	for(int i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
	
	return 0;
}



//
//#include<stdio.h>
//#include<stdlib.h>
//	void swap(int *a,int *b)
//	{
//		int temp=*a;
//		*a=*b;
//		*b=temp;
//	}
//	
//	
//int partition(int ar[],int low,int high)
//{ int pivot=low;
//		while(low<=high)
//	{
//		if(low==high)
//		{	
//	if(ar[high]>=ar[pivot])
//		{
//		high--;	
//		}
//		else if(ar[low]<=ar[pivot])
//		{
//			low++;	
//		}
//		  	swap(&high,&pivot);
//			swap(&ar[high],&ar[pivot]);
//			
//			 	
//			 
//		}
//		
//		else if((ar[low]>ar[pivot])&& (ar[high]<ar[pivot]))
//		{
//			swap(&ar[low],&ar[high]);
//			
//			
//		}
//		 else if(ar[high]>=ar[pivot])
//		{
//		high--;	
//		}
//		 else if(ar[low]<=ar[pivot])
//		{
//			low++;	
//		}
//	    
//		
//	} 
//	return pivot;
//	
//
//}
//
//void quickSort(int arr[], int low, int high) {
//    if (low < high) {
//    	
//        int pi = partition(arr, low, high);
//        printf("\n %d",pi);
//        quickSort(arr, low, pi - 1);
//        quickSort(arr, pi + 1, high);
//    }
//}
//
//
//int main()
//{
//	int n;
//	printf("enter number of element in array:");
//	scanf("%d",&n);
//	printf("\n enter elements in array:");
//	
//	int *arr=(int *)malloc(n*sizeof(int));
//	
//	
//	for(int i=0;i<n;i++)
//	{
//	scanf("%d",&arr[i]);	
//	}
//	
//
//	printf("\n element in array are pahile:");
//	for(int i=0;i<n;i++)
//	{
//		printf("%d  ",arr[i]);
//	}
//int low=0;
//int high=n-1;
//
//quickSort(arr,low,high);
//
//	
//	printf("\n element in array are nantr:");
//	for(int i=0;i<n;i++)
//	{
//		printf("%d  ",arr[i]);
//	}
//	
//	return 0;
//}
