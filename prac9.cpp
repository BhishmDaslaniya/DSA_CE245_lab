#include<bits/stdc++.h>
using namespace std;
typedef long long l;

l callQueue[100];
l start=0;
l take=0;

void In(l num){
  if(start==100){
    cout<<"Overflow"<<endl;
  }else{
    callQueue[start++]=num;
  }
}

void Out(){
    cout<<callQueue[take++]<<" received..."<<endl;
}
void show(){
  if(take==start){
    cout<<"No one is in Queue..."<<endl;
  }else{
    for(l i = take; i < start ;i++){
      cout<<callQueue[i]<<endl;
    }
  }
}
int main(){
  l Choice;
  do{
    cout<<"-------------------------------------"<<endl;
    cout<<"0.Exit :"<<endl;
    cout<<"1.Enter incoming number :::"<<endl;;
    cout<<"2.Pick a call :::"<<endl;
    cout<<"3.Show numbers in Queue :::"<<endl;
    cout<<"Enter Choice: ";
    cin>>Choice;
    if(Choice==1){
      l temp;
      cout<"Number is : ";
      cin>>temp;
      In(temp);
    }else if(Choice==2){
      Out();
    }else if(Choice==3){
      show();
    }else{
      cout<<"Please enter correct "<<endl;
    }
  }while(Choice!=0);
  return 0;
}
