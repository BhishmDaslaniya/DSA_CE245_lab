#include<stdio.h>
int main(){
    int count=0;
    long int sc;
    FILE *f;
    f=fopen("input2.txt","r");
    while(fscanf(f,"%ld",&sc)!=-1){
        count++;
    }
    fclose(f);
    long int no[count];
    int i=0;
    long int s;
    f=fopen("input2.txt","r");
    while(fscanf(f,"%ld",&s)!=-1){
        no[i]=s;
        i++;
    }
    fclose(f);
    long int aadharNo;
    int l,m;
    printf("Enter Aadhaar no: ");
    scanf("%ld",&aadharNo);
    int fm=0;
    l=count-1;
    m=(fm+l)/2;
    while(fm<=l){
        if(no[m]<aadharNo){
            fm=m+1;
        }else if (no[m]==aadharNo){
            printf("Index is %d.\n",m+1);
            break;
        }else{
           l=m-1;
        }
        m=(fm+l)/2;
    }
    if(fm>l){     printf("Sorry!Aadhar no does not exists.\n");  }
    return 0;
}
