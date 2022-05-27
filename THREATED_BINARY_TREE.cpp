// DHIRAJ LAXMAN DARAKHE
// 21118 (com)
// PICT, PUNE


#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *rchild;
    Node *lchild;
    int data;
    int rbit, lbit;
    Node()
    {
        rchild = lchild = NULL;
        data = 0;
        rbit = lbit = 0;
    }
    friend class TBT;
};
class TBT
{
public:
    Node *head, *root;
    TBT()
    {
        head = root = NULL;
    }
    void Create(int x)
    {

        Node *new_node = new Node;
        Node *temp = root;
        new_node->data = x;
        if (root == NULL)
        {
            head = new Node;
            root = new_node;
            head->data = -999;
            head->lbit = 0;
            head->lchild = root;
            head->rbit = 0;
            head->rchild = head;
            root->rbit = root->lbit = 1;
            root->rchild = root->lchild = head;
            return;
        }
        else
        {
            while (true)
            {
                if (x < temp->data)
                {
                    if (temp->lbit == 1)
                    {
                        new_node->lchild = temp->lchild;
                        new_node->rchild = temp;
                        new_node->lbit = new_node->rbit = 1;
                        temp->lchild = new_node;
                        temp->lbit = 0;
                        return;
                    }
                    else
                    {
                        temp = temp->lchild;
                    }
                }
                else if (x > temp->data)
                {
                    if (temp->rbit == 1)
                    {
                        new_node->rchild = temp->rchild;
                        new_node->lchild = temp;
                        new_node->lbit = new_node->rbit = 1;
                        temp->rchild = new_node;
                        temp->rbit = 0;
                        return;
                    }
                    else
                    {
                        temp = temp->rchild;
                    }
                }
                else
                {
                    cout << "Dublicate Vaule !!! : " << endl;
                    return;
                }
            }
        }
    }
    void Inorder()
    {
        Node *rtemp = root;
        while (rtemp != head)
        {

            while (rtemp->lbit == 0)
            {
                rtemp = rtemp->lchild;
            }
            cout << rtemp->data << " ";
            while (rtemp->rbit == 1)
            {
                rtemp = rtemp->rchild;
                if (rtemp == head)
                {
                    return;
                }

                cout << rtemp->data << " ";
            }
            rtemp = rtemp->rchild;
        }
    }
    void Preorder()
    {
        Node *rtemp = root;
        while (rtemp != head)
        {

            while (rtemp->lbit == 0)
            {
                cout << rtemp->data << " ";
                rtemp = rtemp->lchild;
            }
            cout << rtemp->data << " ";
            while (rtemp->rbit == 1)
            {
                rtemp = rtemp->rchild;
                if (rtemp == head)
                {
                    return;
                }
                // cout << rtemp->data << " ";
            }
            rtemp = rtemp->rchild;
        }
    }
};

int main()
{

    TBT obj;
    char ans = 'y';
    do
    {
        cout << "\n\t\tMENU**\n"
             << "1) Create the TBT \n 2) Inodrder TReversal\n 3) Preorder Traversal \n"
             << " Enter Ur choice\n";
        int a;
        cin >> a;
        int dt = 0;
        switch (a)
        {
        case 1:
            cout << "Enter the data \n";
            cin >> dt;
            obj.Create(dt);
            break;
        case 2:
            cout << "Inoder Traversal\n";
            obj.Inorder();
            break;
        case 3:
            cout << "Preorder Traversal\n";
            obj.Preorder();
            break;
        default:

            cout << "Do want to continue(y/n)\n";
            cin >> ans;
            break;
        }
    } while (ans == 'y');
    return 0;
}