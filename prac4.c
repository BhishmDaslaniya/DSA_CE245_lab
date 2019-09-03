#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *fp;
  fp = fopen("input4.txt","r");
  int count = 0;
  int sc;
  while(fscanf(fp,"%d\n",&sc)!=-1){
    count++;
  }
  fclose(fp);
  int arr[count];
  fp = fopen("input4.txt","r");
  for(int i = 0 ; i < count ;i++){
    fscanf(fp,"%d\n",&sc);
    arr[i] = sc;
  }
  fclose(fp);
  for(int i=0;i < count ;i++){
    for(int j =i+1;j < count;j++){
      if(arr[i]>arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  for(int i = 0 ; i < count ; i++){
    int temp = arr[i];
    int j = i+1;
    int ans = 0;
    while (arr[j]==temp) {
      ans++;
      j++;
    }
    i = j-1;
    printf("no of duplicates of %d = %d",arr[i],ans);
    printf("\n");
  }
  return 0;
}
