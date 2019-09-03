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

  float min = arr[0];

  for(int i = 0 ; i < count-1 ; i++){
      int min_index = i;
      for(int j = i+1 ; j < count ; j++){
        if(arr[j] < arr[min_index]){
          min_index=j;
        }
      }
      if(min_index!=i){
      float temp = arr[min_index];
      arr[min_index]=arr[i];
      arr[i] = temp;
    }
  }
  for(int i = 0 ; i < count ;i++){
    printf("%.2f\n",arr[i]);
  }
  return 0;
}
