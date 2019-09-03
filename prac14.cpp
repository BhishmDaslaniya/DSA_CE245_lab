#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int front = -1, rear = -1;
int mat[MAX][MAX] = {0};
int nqueue[MAX];

int visited[MAX] = {0};
void insert_queue(int vertex)
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        nqueue[rear] = vertex;
    }
}

int isEmpty_queue()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int delete_item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = nqueue[front];
    front = front + 1;
    return delete_item;
}

void BFS(int n, int start_vertex)
{
    int state[n] = {0}; //0 for not visited!
    insert_queue(start_vertex);
    state[start_vertex] = -1; //-1 for waiting!
    while (!isEmpty_queue())
    {
        start_vertex = delete_queue();
        cout << start_vertex << " ";
        state[start_vertex] = 1; //1 for visited!
        for (int i = 0; i < n; i++)
        {
            if (mat[start_vertex][i] == 1 && state[i] == 0)
            {
                insert_queue(i);
                state[i] = -1;
            }
        }
    }
    cout << "\n";
}

void DFS(int i, int n)
{
    int j;
    cout << i << " ";
    visited[i] = 1;
    for (j = 0; j < n; j++)
        if (!visited[j] && mat[i][j] == 1)
            DFS(j, n);
}

int main()
{
    int n;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << ":::Enter edge by give two vertices:::" << endl;
    for (int i = 1; i < (n * (n - 1)); i++)
    {
        int start, end;
        cout << "Enter connected edge " << i << " (-1 -1 for exit) : ";
        cin >> start >> end;
        if (start == -1 && end == -1)
        {
            break;
        }
        else if (start >= n || end >= n || start < 0 || end < 0)
        {
            //0<vertices<=n//
            cout << "Invalid edge!" << endl;
            i--;
        }
        else
        {
            mat[start][end] = 1;
        }
    }
    int start_vertex;
    int ch;
    do
    {
        cout << "\n0.Exit";
        cout << "\n1.BFS traversal";
        cout << "\n2.DFS traversal";
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter Start vertex : ";
            cin >> start_vertex;
            BFS(n, start_vertex);
            break;
        case 2:
            DFS(0, n);
            break;
        }
    } while (ch != 0);
    return 0;
}