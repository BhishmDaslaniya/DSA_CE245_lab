#include<stdio.h>

int main(){

  FILE *fp;
  fp = fopen("input5.txt","r");
  int count = 0;
  float sc;
  while(fscanf(fp,"%f\n",&sc)!=-1){
    count++;
  }
  fclose(fp);
  double arr[count];
  fp = fopen("input5.txt","r");
  for(int i = 0 ; i < count ;i++){
    fscanf(fp,"%f\n",&sc);
    arr[i] = sc;
  }
  fclose(fp);
  float key;
  for(int i = 1 ; i < count ; i++){
    key = arr[i];
    int j = i-1;
    while(j>=0 && arr[j]>key){
      arr[j + 1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key;
  }
  for(int i = 0 ; i < count ;i++){
    printf("%.2f\n",arr[i]);
  }
    return 0;
}
