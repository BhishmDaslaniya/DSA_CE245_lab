#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *fp;
  fp = fopen("input3.txt","r");
  int count = 0;
  int sc;
  while(fscanf(fp,"%d\n",&sc)!=-1){
    count++;
  }
  fclose(fp);
  int arr[count];
  fp = fopen("input3.txt","r");
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
  int choice;
  printf("Enter your choice\n1.Largest number\n2.Smallest number\n");
  scanf("%d",&choice);
  if(choice==1){
    int k;
    printf("Enter position of largest number : ");
    scanf("%d",&k);
    printf("%d largest no. is %d\n",k,arr[count - k]);
  }else if(choice==2){
    int k;
    printf("Enter position of smallest number : ");
    scanf("%d",&k);
    printf("%d smallest no. is %d\n",k,arr[k-1]);
  }
  return 0;
}
