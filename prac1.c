#include<stdio.h>
int main(){
  FILE *f;
  f = fopen("input.txt","r");
  int count = 0;
  long int s;
  while(fscanf(f,"%ld",&s) != -1){
    count++;
  }
  fclose(f);
  int ans = 0,flag = 0;
  long int sc;
  printf("Enter aadhar no :- ");
  long int aadharNo;
  scanf("%ld",&aadharNo);
  f = fopen("input.txt","r");
  for(int i = 0 ; i < count ;i++){
    fscanf(f,"%ld",&sc);
    if(aadharNo==sc){
      flag = 1;
      ans = i+1;
      break;
    }
  }
  fclose(f);
  if(flag==1){
    printf("Index no is %d \n",ans);
  }else{
    printf("Sorry! Aadhar no. is not exist... \n");
  }
  return 0;
}
