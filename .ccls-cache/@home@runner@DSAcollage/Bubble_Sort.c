#include <stdio.h>

int main()
{
  int arr[]={6,3,9,5,2,8};
  int i,j,temp;
  
    for(j=0;j<6;j++){
        for(i=0;i<6;i++){
            if(arr[j] < arr[i]){
              temp = arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
            } 
        }
    } 
  for(j=0;j<6;j++){
     printf("%d ",arr[j]);
    }
 
}
