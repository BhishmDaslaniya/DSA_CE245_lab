#include<bits/stdc++.h>
using namespace std;

int CircularQueue[5];
int front=0;
int rear=0;
int c=0;

void Enque(int x)
{
	if(c==5)
	{
		cout<<"\nOverflow";
	}
	else
	{
		CircularQueue[rear]=x;
		rear=(rear+1)%5;
		c++;
	}
}

void Deque()
{
	if (c==0)
	{
		cout<<"\nUnderflow";
	}

	else
	{
		cout<<"\n"<<CircularQueue[front]<<" deleted";
		front=(front+1)%5;
		c--;
	}


}

void show()
{
  if(c==0){
    cout<<"\nUnderflow";
  }
	for (int i = 0; i<c; i++)
	{
		cout<<CircularQueue[(i+front)%5]<<"\t";
	}
}

int main()
{
	int ch, x;
	do
	{
    cout<<"\n0. Exit";
		cout<<"\n1. Insert";
		cout<<"\n2. Delete";
		cout<<"\n3. Print";
		cout<<"\nEnter Your Choice : ";
		cin>>ch;
		if (ch==1)
		{
      if(c==5){
        cout<<"\nOverflow";
      }else{
			cout<<"\nInsert : ";
			cin>>x;
			Enque(x);
      }
		}
		else if (ch==2)
		{
			Deque();
		}
		else if (ch==3)
		{
			show();
		}else{
      cout<<"Enter correct input"<<endl;
    }
	}
	while(ch!=0);

	return 0;
}
