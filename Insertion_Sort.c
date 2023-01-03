#include <stdio.h>

int main()
{
  int arr[]={6,3,9,5,2,8};
  int i,j,temp,current;
  for(i=1;i<6;i++){
      current = arr[i];
      j = i-1;
      while(j>=0 && current < arr[j]){
          arr[j+1] = arr[j];
          j--;
      }
      
      arr[j+1] = current;
      
  }
  
  for(j=0;j<6;j++){
     printf("%d ",arr[j]);
    }
    return 0;
}
