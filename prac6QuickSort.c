#include<stdio.h>

void swap(int *a , int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Partition(int arr[],int startIndex, int endIndex){
  int pivot = arr[endIndex];
  int PartitionIndex = startIndex;
  for(int i = startIndex ; i < endIndex;i++){
    if(arr[i]<=pivot){
      swap(&arr[i],&arr[PartitionIndex]);
      PartitionIndex++;
    }
  }
  swap(&arr[PartitionIndex],&arr[endIndex]);
  return PartitionIndex;
}

void QuickSort(int arr[] , int startIndex , int endIndex){
  if(startIndex < endIndex){
  int PartitionIndex = Partition(arr,startIndex,endIndex);
  QuickSort(arr,startIndex,PartitionIndex-1);
  QuickSort(arr,PartitionIndex+1,endIndex);
  }
}

int main(){
  printf("Give size of array : \n" );
  int size;
  scanf("%d",&size);
  int arr[size];
  printf("Enter array values:\n" );
  for(int i = 0 ; i < size ; i++){
    scanf("%d",&arr[i] );
  }
  QuickSort(arr,0,size-1);
  printf("sorted array is : \n" );
  for(int i = 0 ; i < size ; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");

  return 0;
}
