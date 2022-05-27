// DHIRAJ LAXMAN DARAKHE
// 21118 (com)
// PICT, PUNE


#include <bits/stdc++.h>
using namespace std;
class Node
{
    Node *next;
    int data;

public:
    Node()
    {
        next = NULL;
        data = 0;
    }
    Node(int t)
    {
        next = NULL;
        data = t;
    }
    friend class Traversal;
};
class Queue
{

    int rare;
    int front;
    int *arr;

public:
    Queue()
    {
        rare = -1;
        front = -1;
        arr = new int[50];
    }
    bool Empty()
    {
        if (front == -1 || front == rare + 1)
        {
            return 1;
        }
        return 0;
    }
    void Enqueue(int temp)
    {
        if (Empty())
        {
            rare = -1;
            front = -1;
        }
        if (rare == -1 && front == -1)
        {
            front++;
        }
        rare++;
        arr[rare] = temp;
    }
    int Dequeue()
    {
        if (Empty())
            return 0;
        int temp = arr[front];
        front++;
        return temp;
    }
    friend class Traversal;
};
class Stack
{
    int top;
    int *arr;

public:
    Stack()
    {
        top = -1;
        arr = new int[50];
    }
    void push(int key)
    {
        top++;
        arr[top] = key;
    }
    int pop()
    {
        if (top == -1)
        {
            return 0;
        }
        int res = arr[top];
        top--;
        return res;
    }
    bool Empty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }
    friend class Traversal;
};
class Traversal
{
    int vertex;
    Node **LinkedList;

public:
    Traversal() { vertex = 0; }
    Traversal(int v)
    {
        vertex = v;
        LinkedList = new Node *[v];
        for (int i = 0; i < v; i++)
        {

            LinkedList[i] = NULL;
        }
    }
    void Insert()
    {
        int v1, v2;
        cout << "\nEnter the edges : ";
        cin >> v1 >> v2;
        Node *new_node = new Node(v2);
        Node *temp = LinkedList[v1];
        if (temp == NULL)
        {
            LinkedList[v1] = new_node;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void display()
    {
        cout << "\nGraph is : ";
        for (int i = 0; i < vertex; i++)
        {
            Node *temp = LinkedList[i];
            cout << i << " : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void BFS(int start)
    {
        Queue q;
        int *visited = new int[vertex];
        for (int i = 0; i < vertex; i++)
        {
            visited[i] = 0;
        }
        q.Enqueue(start);
        visited[start] = 1;
        while (!q.Empty())
        {
            int t = q.Dequeue();
            cout << t << " ";
            Node *temp = LinkedList[t];
            while (temp)
            {
                if (visited[temp->data] == 0)
                {
                    q.Enqueue(temp->data);
                    visited[temp->data] = 1;
                }
                temp = temp->next;
            }
        }
    }
    void DFS(int start)
    {
        Stack q;
        int *visited = new int[vertex];
        for (int i = 0; i < vertex; i++)
        {
            visited[i] = 0;
        }
        q.push(start);
        visited[start] = 1;
        while (!q.Empty())
        {
            int t = q.pop();
            cout << t << " ";
            Node *temp = LinkedList[t];
            while (temp)
            {
                if (visited[temp->data] == 0)
                {
                    q.push(temp->data);
                    visited[temp->data] = 1;
                }
                temp = temp->next;
            }
        }
    }
};
int main()
{
    int v;
    cout << "\nEnter the number vertices : ";
    cin >> v;
    Traversal t(v);
    int e;
    cout << "\nEnter the edges ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        t.Insert();
    }
    t.display();
    cout << endl;
    cout << "**** DFS ****\n";
    t.DFS(0);
    cout << "**** BFS ****\n";
    t.BFS(0);
    return 0;
}