#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int low,int high,int n)
{
	int mid=low+high/2;
	int len1=mid-low+1;
	int len2=high-mid;
	
	int *first=new int[len1];
	int *second=new int[len2];
	
	//copy values
	int mainarrayindex=low;
	for(int i=0;i<len1;i++)
	{
		first[i]=arr[mainarrayindex];
	mainarrayindex++;
	}
	mainarrayindex=mid+1;
	for(int i=0;i<len2;i++)
	{
		second[i]=arr[mainarrayindex];
		mainarrayindex++;
	}
	printf("\n first");
	for(int i=0;i<len1;i++)
	{
		printf("%d  ",first[i]);
	}
		printf("\n second:");
	for(int i=0;i<len2;i++)
	{
		printf("%d  ",second[i]);
	}
	
	int index1=0;
	int index2=0;
	mainarrayindex=low;
	
	while(index1<len1 && index2<len2)
	{
		if(first[index1]<second[index2])
		{
			arr[mainarrayindex]=first[index1];
			mainarrayindex++;
			index1++;
		}
		else
		{
			arr[mainarrayindex]=second[index2];
			mainarrayindex++;
			index2++;
		}
	}
	
	while(index1<len1)
	{
	arr[mainarrayindex]=first[index1];
			mainarrayindex++;
			index1++;
	}
	
		while(index2<len2)
	{
	arr[mainarrayindex]=first[index2];
			mainarrayindex++;
			index2++;
	}
	
		printf("\n sorted array:");
	for(int i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
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

merge(arr,low,high,n);

	

	
	return 0;
}
