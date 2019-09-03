#include<iostream>
using namespace std;

struct nodeClass
{
	int id;
	nodeClass *next;
};

nodeClass *head;

void insert(int x)
{

	nodeClass *t=head;
	if (head!=NULL)
	{
			while(t->next!=NULL)
		{
			t=t->next;
		}
		nodeClass *n= new nodeClass;
		t->next=n;
		n->id=x;
		n->next=NULL;
	}
	else
	{
		nodeClass *n= new nodeClass;
		n->id=x;
		n->next=NULL;
		head=n;
	}
}

void remove(int x)
{
	nodeClass *t=head;
	nodeClass *p;
	while(t->id!=x)
	{
		p=t;
		t=t->next;
	}
	if(head->id==x){
		head = t->next;
	}else{
		p->next=t->next;
	}
	t->next=NULL;
	delete t;
}

void show()
{
	nodeClass *t=head;
	while(t!=NULL)
	{
		cout<<t->id<<"\t";
		t=t->next;
	}

}
void sort()
{
	struct nodeClass *new1 = head;
	struct nodeClass *count;
	for( ; new1->next != NULL; new1 = new1->next)
	{
		for(count = new1->next; count != NULL; count = count->next)
		{
			if(new1->id > count->id)
			{
				int temp = new1->id;
				new1->id = count->id;
				count->id = temp;
			}
		}
	}
	cout<<"Ascending Sort completed!!!"<<endl;
}

int main()
{
	int choice, x;
	do
	{
    cout<<"\n0. Exit";
		cout<<"\n1. Insert";
		cout<<"\n2. Delete";
		cout<<"\n3. Print";
    cout<<"\n4. Sort";
		cout<<"\n\nEnter you choice : ";
		cin>>choice;
		switch (choice)
		{
			case 1 :cout<<"\nEnter the student id : ";
					 		cin>>x;
					 		insert(x);	break;
			case 2 :cout<<"\nEnter the student id for remove : ";
							cin>>x;
							remove(x); 	break;
			case 3 : show();	break;
      case 4 : sort(); break;
		}
	}
	while(choice!=0);
	return 0;
}
