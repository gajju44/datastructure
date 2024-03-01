// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
struct dyn
   {
   int data;
   };
int main() 
{
   
   int element;
   int n;
   printf("\nEnter size of array:");
   scanf("%d",&n);
   printf("\n enter element in array:");
   struct dyn *arr=(struct dyn*)malloc(n*sizeof(struct dyn));
   for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i].data);
    }
   printf("\n enter element you want to find:");
   scanf("%d",&element);
   int low=0;
   int high=n-1;
   int mid;
while(low<=high){
mid=(low+high)/2;
   if(arr[mid].data==element)
   {
       printf("\n element is present at %d position.",mid+1);
       break;
   }
   else if(arr[mid].data>element)
   {
       high=mid-1;
   }
   else
   {
       low=mid+1;
   }
  
}
if(low>high)
{
	printf("element not found");
}
   free(arr);
    return 0;
}
