// DHIRAJ LAXMAN DARAKHE
// 21118 (com)
// PICT, PUNE

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node()
    {
        data = 0;
        left = right = NULL;
    }
    Node(int data)
    {
        this->left = NULL;
        this->data = data;
        this->right = NULL;
    }
};
class Stack
{
public:
    int size;
    int top;
    Node **ar;
    Stack()
    {
        top = -1;
        size = 100;
        ar = new Node *[size];
    }
    void push(Node *t)
    {
        if (this->size - 1 == this->top)
        {
            cout << "\n Stack overflow ";
        }
        else
        {
            this->top++;
            this->ar[this->top] = t;
        }
    }
    Node *pop()
    {
        Node *temp;
        if (this->top == -1)
        {
            cout << "\n Stack underflow ";
        }
        else
        {
            temp = this->ar[this->top];
            this->top--;
            return temp;
        }
    }
};
class QueueOperation
{
    int front;
    int rear;
    int size;
    Node **Q;

public:
    QueueOperation()
    {
        front = -1;
        rear = -1;
        size = 100;
        this->Q = new Node *[this->size];
    }
    void Enqueue(Node *temp);
    Node *Dequeue();
    int isEmpty();
    int isFull();
};
int QueueOperation ::isEmpty()
{

    return front == rear;
}
int QueueOperation ::isFull()
{

    return size - 1 == rear;
}
void QueueOperation ::Enqueue(Node *temp)
{
    if (isFull())
    {
        cout << "\n OverFlow Condition is Encountered  ";
    }
    else
    {
        rear++;
        Q[rear] = temp;
    }
}
Node *QueueOperation ::Dequeue()
{
    Node *o = NULL;
    if (isEmpty())
    {
        cout << "\n UnderFlow Condition is Encountered  ";
    }
    else
    {
        front++;
        o = Q[front];
    }
    return o;
};
class TreeOperation
{
    Node *root;

public:
    TreeOperation()
    {
        root = new Node;
    }
    void CreateTree1()
    {
        Node *p, *t;
        QueueOperation *queueoperation = new QueueOperation;
        cout << "\nEnter the element for root node ";
        int dt;
        cin >> dt;
        p = new Node(dt);
        // root = new Node;
        root = p;
        queueoperation->Enqueue(p);
        while (!queueoperation->isEmpty())
        {
            t = queueoperation->Dequeue();
            cout << "\nEnter the data for left node of " << t->data << " or  Enter -1 if not : ";
            cin >> dt;
            if (dt != -1)
           
            {
                p = new Node(dt);
                t->left = p;
                queueoperation->Enqueue(p);
            }
            cout << "\nEnter the data for right node of " << t->data << " or  Enter -1 if not : ";
            cin >> dt;
            if (dt != -1)
            {
                p = new Node(dt);
                t->right = p;
                queueoperation->Enqueue(p);
            }
        }
    }
    Node *CreateTree2(string s, int dt)
    {
        int Data = 0;
        if (dt == 0)
            cout << "\nDo U Want to create the node at " << s << " (1/0) " << endl;
        else
            cout << "\nDo U Want to create the node at " << s << " of " << dt << " (1/0) " << endl;
        int choice;
        Node *new_node = new Node;
        cin >> choice;
        if (choice)
        {
            cout << "\nEnter the Data to Store in the tree " << endl;
            cin >> Data;
            new_node->data = Data;
            new_node->left = CreateTree2("left", new_node->data);
            new_node->right = CreateTree2("right", new_node->data);
        }
        else
        {
            new_node = NULL;
            return new_node;
        }
        return new_node;
    }
    void CreateTree2()
    {
        root = CreateTree2("Top", 0);
    }
    void Inorder1()
    {
        Inorder1(root);
    }
    void Inorder2()
    {
        Inorder2(root);
    }
    void Preorder1()
    {
        Preorder1(root);
    }
    void Preorder2()
    {
        Preorder2(root);
    }
    void Postorder1()
    {
        Postorder1(root);
    }
    void Postorder2()
    {
        Postorder2(root);
    }
    void Mirror()
    {
        Mirror(root);
    }
    void DeleteTree()
    {
        DeleteTree(root);
    }
    void Inorder1(Node *root)
    {
        Node *p;
        p = root;
        if (p == NULL)
        {
            return;
        }
        Inorder1(p->left);
        cout << p->data << " ";
        Inorder1(p->right);
    }
    void Preorder1(Node *root)
    {
        Node *p;
        p = root;
        if (p == NULL)
        {
            return;
        }
        cout << p->data << " ";
        Preorder1(p->left);
        Preorder1(p->right);
    }
    void Postorder1(Node *root)
    {
        Node *p;
        p = root;
        if (p == NULL)
        {
            return;
        }
        Postorder1(p->left);
        Postorder1(p->right);
        cout << p->data << " ";
    }
    void Mirror(Node *root)
    {
        Node *p;
        p = root;
        if (p == NULL)
        {
            return;
        }
        Mirror(p->left);
        Mirror(p->right);
        swap(p->left, p->right);
    }
    void DeleteTree(Node *root)
    {
        Node *p;
        p = root;
        if (p == NULL)
        {
            return;
        }
        DeleteTree(p->left);
        DeleteTree(p->right);
        delete p;
    }
    void Inorder2(Node *root)
    { 
        Stack st;
        Node *t = root;

        while (1)
        {

            if (t != NULL)
            {
                cout << t->data << " ";
                st.push(t);
                t = t->left;
            }
            else
            {
                t = st.pop();
                t = t->right;
            }
            if (t == NULL && st.top == -1)
            {
                break;
            }
        }
    }
    void Preorder2(Node *root)
    {
        Stack st;
        Node *t = root;

        while (1)
        {

            if (t != NULL)
            {

                st.push(t);
                t = t->left;
            }

            else
            {
                t = st.pop();
                cout << t->data << " ";
                t = t->right;
            }
            if (t == NULL && st.top == -1)
            {
                break;
            }
        }
    }
    void Postorder2(Node *root)
    {
        Stack st;
        Node *t = root;

        while (1)
        {

            if (t != NULL)
            {

                st.push(t);
                t = t->left;
            }

            else
            {
                t = st.pop();
                cout << t->data << " ";
                t = t->right;
            }
            if (t == NULL && st.top == -1)
            {
                break;
            }
        }
    }
    int count()
    {
        return count(root);
    }
    int count(Node *root)
    {
        Node *t = root;
        if (t)
        {
            return count(t->left) + count(t->right) + 1;
        }
        return 0;
    }
    int height()
    {
        return height(root);
    }
    int height(Node *root)
    {
        Node *t = root;
        int l, r;
        if (t)
        {
            l = height(t->left);
            r = height(t->right);
            if (l > r)
            {
                return l + 1;
            }
            else
            {
                return r + 1;
            }
        }
        return 0;
    }
    int getLeafCount()
    {
        getLeafCount(root);
    }
    int getLeafCount(Node *root)
    {
        Node *t = root;
        if (t == NULL)
            return 0;
        if (t->left == NULL && t->right == NULL)
            return 1;
        else
            return getLeafCount(t->left) +
                   getLeafCount(t->right);
    }
};

int main()
{
    int choice;

    cout << " \t\n Create the binary tree" << endl
         << "  \t 1) (Iterative way)" << endl
         << "  \t 2) (Recursive way)" << endl;
    cin >> choice;
    TreeOperation treeoperation;
    if (choice == 1)
    {
        cout << "\n\t**** Create the Tree ((iterative way)or(level order))  *****\n";
        treeoperation.CreateTree1();
    }
    else
    {
        cout << "\n\t**** Create the Tree ((Recursive way)or())  *****\n";
        treeoperation.CreateTree2();
    }
    int choice1;
    
    
    cout << "\n**** Inorder Traversal (Recursive way) *****\n";
    treeoperation.Inorder1();
    cout << "\n**** Preorder Traversal (Recursive way) *****\n";
    treeoperation.Preorder1();
    cout << "\n**** Postorder Traversal  (Recursive way) *****\n";
    treeoperation.Postorder1();
    cout << "\n**** Inorder Traversal (iterative way) *****\n";
    treeoperation.Inorder2();
    cout << "\n**** Preorder Traversal (iterative way) *****\n";
    treeoperation.Preorder2();
    cout << "\n**** Postorder Traversal  (iterative way) *****\n";
    treeoperation.Postorder2();
    cout << "\n**** Postorder Traversal  (Recursive way) *****\n";
    treeoperation.Postorder1();
    cout << "\n**** Total number of node *****\n";
    cout << treeoperation.count();
    cout << "\n**** Total number of leaf node *****\n";
    cout << treeoperation.getLeafCount();
    cout << "\n**** Total number of internal node *****\n";
    cout <<  treeoperation.count() - treeoperation.getLeafCount();
    cout << "\n**** Total height of tree *****\n";
    cout << treeoperation.height();
    cout << "\n**** Mirror of tree *****\n";
    treeoperation.Mirror();
    cout << "\n**** Inorder Traversal (Recursive way) *****\n";
    treeoperation.Inorder1();
    cout << "\n**** Delete the tree *****\n";
    treeoperation.DeleteTree();
    cout << "\n**** Inorder Traversal (Recursive way) *****\n";
    treeoperation.Inorder1();

    return 0;
}
