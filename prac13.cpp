#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

void Insert(struct node *n , int x){
    if (x < n->val)
	{
		if (n->left==NULL)
		{
			struct node *temp=new node;
			temp->val=x;
			temp->left=NULL;
			temp->right=NULL;
			n->left=temp;
		}
		else
		{
			Insert(n->left, x);
		}
	}
	else if(x > n->val)
	{
		if (n->right==NULL)
		{
			struct node *temp=new node;
			temp->val=x;
			temp->left=NULL;
			temp->right=NULL;
			n->right=temp;
		}
		else
		{
			Insert(n->right, x);
		}
	}
}

void Pre(struct node *n)
{
	if (n!=NULL)
	{
		cout<<n->val<<"  ";
		Pre(n->left);
		Pre(n->right);
	}
}

void In(struct node *n)
{
	if (n!=NULL)
	{
		In(n->left);
		cout<<n->val<<"  ";
		In(n->right);
	}
}


void Post(struct node *n)
{
	if (n!=NULL)
	{
		Post(n->left);
		Post(n->right);
		cout<<n->val<<"  ";
	}
}

void PredAndSuc(struct node *n, struct node*& pre, struct node*& suc ,int val){
	if(n == NULL)
		return;
	if(n->val == val){
		if(n->left != NULL){
			struct node *temp = n->left;
			while(temp->right){
				temp = temp->right;
			}
			pre = temp;
		}
		if (n->right != NULL)
		{
			struct node *temp = n->right;
			while (temp->left)
			{
				temp = temp->left;
			}
			suc = temp;
		}
		return;
	}
	if(n->val > val){
		suc = n;
		PredAndSuc(n->left,pre,suc,val);
	}else{
		pre = n;
		PredAndSuc(n->right,pre,suc,val);
	}
}
bool Search(struct node *root, int val)
{
	while (root != NULL)
	{
		if (val > root->val)
			root = root->right;
		else if (val < root->val)
			root = root->left;
		else
			return true; 
	}
	return false;
}

int main(){
    struct node *root = new node;
    cout<<"Enter the root value : ";
    int ch;
    int num;
    cout<<"Enter Mobile Number (Digit by digit with enter or space): ";
    for(int i = 0 ; i < 10 ; i++ ){
        cin>>num;
        if(i==0){
            root->val = num;
            root->left = NULL;
            root->right = NULL;
        }else{
            Insert(root , num);
        }
    }
	struct node *pre = NULL;
	struct node *suc = NULL;
	do
	{
        cout<<"\n0. Exit";
		cout<<"\n1. Preorder";
		cout<<"\n2. Inorder";
		cout<<"\n3. Postorder";
		cout<<"\n4. Search and Print predecessor and successor";
		cout<<"\nEnter Your Choice : ";
		cin>>ch;
		int x;
		switch(ch)
		{
			case 1:
				Pre(root);
				break;
			case 2:
				In(root);
				break;
			case 3:
				Post(root);
				break;
			case 4:
				int val;
				cout << "Enter value for which you want to find Successor and Predecessor:";
				cin >> val;
				if (Search(root, val))
				{
					PredAndSuc(root, pre, suc, val);
					if (pre != NULL)
					{
						cout << "Predecessor is " << pre->val << endl;
					}
					else
					{
						cout << "No predecessor found!" << endl;
					}
					if (suc != NULL)
					{
						cout << "Successor is " << suc->val << endl;
					}
					else
					{
						cout << "No Successor found!" << endl;
					}
				}
				else
				{
					cout << "Value not Found!!!" << endl;
				}
		}
	}while(ch!=0); 
    return 0;
}