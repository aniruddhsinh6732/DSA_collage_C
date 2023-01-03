#include <stdio.h>
#define N 100

int partition(int arr[ ],int low,int high){
    int pivot = arr[high];
    int i = low - 1;
    int j,temp1,temp2;
   
    for(j=low;j<high;j++){
        if(arr[j] < pivot){
            i++;
            temp1 = arr[i];
            arr[i] = arr[j];
            arr[j] = temp1;
        }
   }
    i++;
    temp2 = arr[i];
    arr[i] = pivot;
    arr[high] = temp2;
    return i;
}

void QuickSort(int arr[ ],int low,int high){
    int pivot_index;
    if(low<high){
        pivot_index = partition(arr,low,high);      
        QuickSort(arr,low,pivot_index-1);
        QuickSort(arr,pivot_index+1,high);
    }
}

int main()
{
   int arr[N];
   int low,high,i;
   printf("enter the number of values for array : ");
   scanf("%d",&high);
   high = high - 1;
   low = 0;
  
   for(i=0;i<high+1;i++){
       printf("enter the value for position %d : ",i);
       scanf("%d",&arr[i]);
   }
   
   QuickSort(arr,low,high);

   for(i=0;i<high+1;i++){
       printf("%d ",arr[i]);
   }
   return 0;
}