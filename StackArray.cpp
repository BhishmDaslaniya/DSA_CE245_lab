#include<bits/stdc++.h>
using namespace std;

int Stack[10];
int top = -1;

void push(int value){
  if(top==10)
	{
		cout<<"\nOverflow";
	}
	else
	{
		Stack[++top]=value;
	}
}

void pop(){
  if (top==0)
	{
		cout<<"\nUnderflow";
	}
	else
	{
		cout<<"\n"<<Stack[top--]<<" deleted";
	}
}

void display(){
  for(int i=0 ; i <= top;i++){
    cout<<Stack[i]<<"\n";
  }
}

int main(){
    int choise,value;

    do{
      cout<<"\n0. Exit";
      cout<<"\n1. Push";
  		cout<<"\n2. Pop";
  		cout<<"\n3. Display";

      cout<<"\nEnter Your Choice : ";
      cin>>choise;
		if (choise==1)
		{
			cout<<"\nInsert : ";
			cin>>value;
			push(value);
		}
		else if (choise==2)
		{
			pop();
		}
		else if (choise==3)
		{
			display();
		}
	}
	while(choise!=0);

}
