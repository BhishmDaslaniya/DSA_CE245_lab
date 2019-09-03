#include<bits/stdc++.h>
using namespace std;


long int MAX = 10000;
long int front = -1,rear = -1;
int queue[MAX];
int 
void insert(int a)
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = a;
    }
}

