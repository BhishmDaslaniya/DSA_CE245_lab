#include <bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	struct node *prev;
	struct node *next;
};

struct node *start;

void insert(int x, int choice)
{
	if (choice == 1)
	{
		if (start != NULL)
		{
			struct node *t = start;
			struct node *n = new node;
			n->val = x;
			n->next = t;
			n->prev = NULL;
			t->prev = n;
			start = n;
		}
		else
		{
			struct node *n = new node;
			n->val = x;
			n->prev = NULL;
			n->next = NULL;
			start = n;
		}
	}
	else if (choice == 2)
	{
		cout << "Enter possition for insert element (Assume that position start form 0!): ";
		int pos, count = 0;
		cin >> pos;
		if (start != NULL)
		{
			struct node *t = start;
			if (pos == 0)
			{
				insert(x, 1);
			}
			else
			{
				while (count != pos - 1)
				{
					if (t->next != NULL)
					{
						t = t->next;
						count++;
					}
					else
					{
						cout << "position not exist!" << endl;
						break;
					}
				}
				if (count == pos - 1)
				{
					struct node *n = new node;
					n->prev = t;
					n->val = x;
					n->next = t->next;
					if (t->next != NULL)
					{
						t->next->prev = n;
					}
					t->next = n;
				}
			}
		}
		else
		{
			cout << "List is Empty!" << endl;
		}
	}
	else if (choice == 3)
	{
		if (start != NULL)
		{
			struct node *t = start;
			while (t->next != NULL)
			{
				t = t->next;
			}
			struct node *n = new node;
			t->next = n;
			n->prev = t;
			n->val = x;
			n->next = NULL;
		}
		else
		{
			struct node *n = new node;
			n->val = x;
			n->prev = NULL;
			n->next = NULL;
			start = n;
		}
	}
}

void remove(int x, int choice)
{
	if (choice == 1)
	{
		struct node *t = start;
		if (start != NULL)
		{
			if (t->next == NULL)
			{
				delete t;
				start = NULL;
			}
			else
			{
				t->next->prev = NULL;
				if (t->next != NULL)
				{
					start = t->next;
				}
				t->next = NULL;
				delete t;
			}
		}
		else
		{
			cout << "List is Empty!" << endl;
		}
	}
	else if (choice == 2)
	{
		cout << "Enter position which you want to delete (position start from 0!): ";
		int pos, count = 0;
		cin >> pos;
		struct node *t = start;
		if (start != NULL)
		{
			if (pos == 0)
			{
				remove(0, 1);
			}
			else
			{
				while (count != pos)
				{
					if (t->next != NULL)
					{
						t = t->next;
						count++;
					}
					else
					{
						cout << "Position not exist!" << endl;
						break;
					}
				}
				if (count == pos)
				{
					t->prev->next = t->next;
					if (t->next != NULL)
					{
						t->next->prev = t->prev;
					}
					t->prev = NULL;
					t->next = NULL;
					delete t;
				}
			}
		}
		else
		{
			cout << "List is Empty!" << endl;
		}
	}
	else if (choice == 3)
	{
		struct node *t = start;
		if (start != NULL)
		{
			while (t->next != NULL)
			{
				t = t->next;
			}
			if (t->prev == NULL)
			{
				delete t;
				start = NULL;
			}
			else
			{
				t->prev->next = NULL;
				t->prev = NULL;
				delete t;
			}
		}
		else
		{
			cout << "List is Empty!" << endl;
		}
	}
	else if (choice == 4)
	{
		struct node *t = start;
		if (start != NULL) // worthless coz already checked in main!!!  LOL ;-)
		{
			while (t->val != x)
			{
				t = t->next;
			}
			if (t->prev == NULL && t->next == NULL)
			{
				delete t;
				start = NULL;
			}
			else if (t->prev == NULL)
			{
				start = t->next;
				t->next->prev = NULL;
				t->next = NULL;
				t->prev = NULL;
				delete t;
			}
			else if (t->next == NULL)
			{
				t->prev->next = NULL;
				t->next = NULL;
				t->prev = NULL;
				delete t;
			}
			else
			{
				t->next->prev = t->prev;
				t->prev->next = t->next;
				t->next = NULL;
				t->prev = NULL;
				delete t;
			}
		}
		else
		{
			cout << "List is Empty!" << endl;
		}
	}
}

int search(int x)
{
	struct node *t = start;
	int found = 0;
	if (start != NULL)
	{
		while (t != NULL)
		{
			if (t->val == x)
			{
				found = 1;
				return found;
			}
			t = t->next;
		}
		if (found == 0)
		{
			return found;
		}
	}
	else
	{
		return -1;
	}
}

void show()
{
	struct node *t = start;
	if (start != NULL)
	{
		while (t != NULL)
		{
			cout << t->val << "\t";
			t = t->next;
		}
	}
	else
	{
		cout << "List is Empty!" << endl;
	}
}

void reverseShow()
{
	struct node *t = start;
	if (start != NULL)
	{
		while (t->next != NULL)
		{
			t = t->next;
		}
		while (t != NULL)
		{
			cout << t->val << "\t";
			t = t->prev;
		}
	}
	else
	{
		cout << "List is Empty!" << endl;
	}
}

int main()
{
	int choice, x, ans;
	do
	{
		cout << "\n0. Exit :-)";
		cout << "\n1. Insert at begining  : ";
		cout << "\n2. Insert at particular position  : ";
		cout << "\n3. Insert at end  : ";
		cout << "\n4. Delete from beginning : ";
		cout << "\n5. Delete from particular position : ";
		cout << "\n6. Delete from end : ";
		cout << "\n7. Delete particular element : ";
		cout << "\n8. Search";
		cout << "\n9. Forward print";
		cout << "\n10. Reverse print";
		cout << "\n\nEnter you choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nEnter the element to be inserted : ";
			cin >> x;
			insert(x, 1);
			break;
		case 2:
			cout << "\nEnter the element to be inserted : ";
			cin >> x;
			insert(x, 2);
			break;
		case 3:
			cout << "\nEnter the element to be inserted : ";
			cin >> x;
			insert(x, 3);
			break;
		case 4:
			remove(0, 1);
			break;
		case 5:
			remove(0, 2);
			break;
		case 6:
			remove(0, 3);
			break;
		case 7:
			cout << "\nEnter the element to be removed : ";
			cin >> x;
			ans = search(x);
			if (ans == 1)
			{
				remove(x, 4);
			}
			else if (ans == 0)
			{
				cout << "Element Not Found!" << endl;
			}
			else
			{
				cout << "List is Empty!" << endl;
			}
			break;
		case 8:
			cout << "\nEnter the element to be searched : ";
			cin >> x;
			ans = search(x);
			if (ans == 1)
			{
				cout << "Found!" << endl;
			}
			else if (ans == 0)
			{
				cout << "Not Found!" << endl;
			}
			else if (ans == -1)
			{
				cout << "List is Empty!" << endl;
			}
			break;
		case 9:
			show();
			break;
		case 10:
			reverseShow();
			break;
		}
	} while (choice != 0);

	return 0;
}
