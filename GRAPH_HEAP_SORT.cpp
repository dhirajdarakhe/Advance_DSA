// DHIRAJ LAXMAN DARAKHE
// 21118 (com)
// PICT, PUNE


#include <iostream>
using namespace std;
class Queue
{
    int rear;
    int front;
    int *Q;
    int size;

public:
    Queue()
    {
        front = rear = -1;
        size = 20;
        Q = new int[size];
    }
    Queue(int x)
    {
        front = rear = -1;
        size = x;
        Q = new int[size];
    }
    void enQueue(int data)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full\n";
        }
        else
        {
            rear++;
            Q[rear] = data;
        }
    }
    int deQueue()
    {
        int x;
        if (front == rear)
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            front++;
            x = Q[front];
        }
        return x;
    }
    int isEmptyQ()
    {
        return rear == front;
    }
    void printQ()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            printf("\n%d\n", Q[i]);
        }
        cout << endl;
    }
};
class Graph
{
    int **matx;
    int vertices;
    int *visited;

public:
    int *indegree;
    Queue q;
    Graph(int n)
    {
        int a = n + 1;
        vertices = n;
        matx = new int *[a];
        indegree = new int[a];
        for (int i = 1; i <= n; i++)
        {
            matx[i] = new int[a];
            for (int j = 1; j <= n; j++)
            {
                matx[i][j] = 0;
            }
        }
    }
    void clear()
    {
        for (int i = 1; i <= vertices; i++)
        {
            visited[i] = 0;
        }
    }
    void addEdge(int a, int b)
    {
        matx[a][b] = 1;
    }
    void printMatrix()
    {
        for (int i = 1; i <= vertices; i++)
        {

            cout << i << "  ";

            for (int j = 1; j <= vertices; j++)
            {
                cout << matx[i][j] << " ";
            }
            cout << endl;
        }
    }

    void indegreeCalculation()
    {
        for (int i = 1; i <= vertices; ++i)
        {
            indegree[i] = 0;
            for (int j = 1; j <= vertices; ++j)
            {
                if (matx[j][i] == 1)
                {
                    indegree[i]++;
                }
            }
            if (indegree[i] == 0)
                q.enQueue(i);
        }
    }
    void topologicalSort()
    {

        int j, k;
        indegreeCalculation();
        while (!q.isEmptyQ())
        {
            j = q.deQueue();
            cout << j << " ";
            for (k = 1; k <= vertices; k++)
            {
                if (matx[j][k] == 1)
                {
                    indegree[k]--; 
                    if (indegree[k] == 0)
                    {
                        q.enQueue(k);
                    }
                }
            }
        }
    }
};

int main()
{
    cout << "Enter the number of vertices in the graph:";
    int v;
    cin >> v;
    Graph G(v);
    cout << "Enter the number of edges in the graph:";
    int e;
    cin >> e;
    int a, b;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter source and destination:";
        cin >> a >> b;
        G.addEdge(a, b);
    }
    cout << "Inputted Graph is:\n";
    cout << "   ";
    for (int i = 1; i <= v; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    G.printMatrix();
    cout << "Topological Sort of the given graph is:";
    G.topologicalSort();

    return 0;
}