#include <stdio.h>

int main()
{
  int arr[]={6,3,9,5,2,8};
  int i,j,temp,min_idx;

  for(min_idx = 0;min_idx<6;min_idx++){
      for(i=min_idx+1;i<6;i++){
          if(arr[min_idx] > arr[i]){  
              temp = arr[i]; 
              arr[i] = arr[min_idx];
              arr[min_idx] = temp;
            }
        }
    }
    
  for(j=0;j<6;j++){
     printf("%d ",arr[j]);
    }
  
  return 0;
}
