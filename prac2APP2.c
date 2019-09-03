#include <stdio.h>

int binarySearch(int A[], int low, int high, int x)
{
    if (low > high)
    {
       return -1;
    }
    int mid = (low + high)/2;
    if (x == A[mid]){
       return mid;
     }
    else if (x < A[mid])
    {
      return binarySearch(A, low,  mid - 1, x);
    }
    else{
      return binarySearch(A, mid + 1,  high, x);
    }
}

int main()
{
    int count=0,flag,f,l,d;
    long int sc;
    FILE *fp;
    fp=fopen("input2.txt","r");

    while(fscanf(fp,"%ld",&sc)!=-1){
      count++;
    }
    int i = 0;
    fclose(fp);
    long int no[count];
    i=0;
    fp=fopen("input2.txt","r");
    while(fscanf(fp,"%ld",&sc)!=-1){
        no[i]=sc;
        i++;
    }
    fclose(fp);
    printf("Enter Aadhaar no :  ");
    long int aadharNo;
    scanf("%ld",&aadharNo);
    d = sizeof(no)/sizeof(no[0]);
    f=0, l=count-1;
    int index = binarySearch(no, f, l, aadharNo);
    if (index != -1)
        printf("Index id %d.\n", index+1);
    else
        printf("Sorry! Aadhar no. does not exists.\n\n");
    return 0;
}
