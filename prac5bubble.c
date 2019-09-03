#include<stdio.h>
#define false 0
#define true 1
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
  int swapped;
  int c = 0;
  for(int i = 0 ; i < count ; i++){
    swapped = false;
    for(int j = 0 ; j < count-1-i ; j++){
      if(arr[j] > arr[j+1]){
        float temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
        c++;
        swapped = true;
      }
    }
    if(swapped==false){
      break;
    }
  }
  for(int i = 0 ; i < count ; i++){
    printf("%.2f\n",arr[i]);
  }
  //printf("\n%d ",c);
  return 0;
}
