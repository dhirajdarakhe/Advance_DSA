//  DHIRAJ LAXMAN DARAKHE
//  21118 SE01
//  AVL TREE

#include <bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    Node *lchild;
    Node *rchild;
    Node()
    {
        data = 0;
        lchild = rchild = NULL;
    }
    Node(int dt)
    {
        data = dt;
        lchild = rchild = NULL;
    }
    friend class AvlTree;
};
class AvlTree
{
    Node *root;

public:
    AvlTree()
    {
        root = NULL;
    }
    int height(Node *rtemp) // to get hight
    {
        if (rtemp)
        {
            int l = height(rtemp->lchild);
            int r = height(rtemp->rchild);
            return max(l + 1, r + 1);
        }
        return 0;
    }
    int getBalancefactor(Node *rtemp) // to get the balanace factor
    {
        if (rtemp)
        {
            return height(rtemp->lchild) - height(rtemp->rchild);
        }
        return 0;
    }
    Node *rightRotation(Node *rtemp)
    {
        Node *z = rtemp;
        Node *y = rtemp->lchild;
        Node *T2 = y->rchild;
        // l rotion
        y->rchild = z;
        z->lchild = T2;
        return y;
    }
    Node *leftRotation(Node *rtemp)
    {
        Node *x = rtemp;
        Node *y = rtemp->rchild;
        Node *T2 = y->lchild;
        // r rotion
        y->lchild = x;
        x->rchild = T2;
        return y;
    }
    Node *createAVL(Node *r, Node *new_node)
    {
        if (r == NULL)
        {
            r = new_node;
            return r;
        }
        else if (r->data > new_node->data)
        {
            r->lchild = createAVL(r->lchild, new_node);
        }
        else if (r->data < new_node->data)
        {
            r->rchild = createAVL(r->rchild, new_node);
        }
        else
        {
            cout << "\nDuplicate Entry denied !! \n";
            return r;
        }
        int bf = getBalancefactor(r);
        if (bf > 1 && r->lchild->data > new_node->data) // left Imbalance subtree
        {
            return rightRotation(r);
        }
        if (bf > 1 && r->lchild->data < new_node->data) // left right Imbalance subtree
        {
            r->lchild = leftRotation(r->lchild);
            return rightRotation(r);
        }
        if (bf < -1 && r->rchild->data < new_node->data) // right Imbalance subtree
        {
            return leftRotation(r);
        }
        if (bf < -1 && r->rchild->data > new_node->data) // rightleft Imbalance subtree
        {
            r->rchild = rightRotation(r->rchild);
            return leftRotation(r);
        }
        return r;
    }
    void insertData(int dt)
    {
        Node *new_node = new Node(dt);
        root = createAVL(root, new_node);
    }
    void preorderTraversal(Node *rtemp)
    {
        Node *temp = rtemp;
        if (temp == NULL)
            return;
        cout << temp->data << " ";
        preorderTraversal(temp->lchild);
        preorderTraversal(temp->rchild);
    }
    void inorderTraversal(Node *rtemp)
    {
        Node *temp = rtemp;
        if (temp == NULL)
            return;
        inorderTraversal(temp->lchild);
        cout << temp->data << " ";
        inorderTraversal(temp->rchild);
    }
    void Traversal(int t)
    {
        if (t == 1)
            inorderTraversal(root);
        if (t == 2)
            preorderTraversal(root);
    }
    int heightAVL()
    {
        return height(root);
    }
};
int main()
{
    AvlTree avl;
    int dt = 0, option;
    do
    {
        cout << "\n\n** MENU **\n";
        cout << "1: Create the AVL tree : \n";
        cout << "2: INorder Traversal :  \n";
        cout << "3: Preorder Traversal :  \n";
        cout << "4: Height of AVL tree : \n";
        cout << "0: Exit \n";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "\n(Enter -1 to stop ) \n";
            while (dt != -1)
            {

                cout << "\nEnter the data : ";
                cin >> dt;
                if (dt != -1)
                    avl.insertData(dt);
            }
            break;
        case 2:
            cout << "\nINORDER TRAVERSAL : ";
            avl.Traversal(1);
            break;
        case 3:
            cout << "\nPREORDER TRAVERSAL : ";
            avl.Traversal(2);
            break;
        case 4:
            cout << "\nHEIGHT OF AVL TREE : ";
            cout << avl.heightAVL();
            break;
        case 0:
            break;
        default:
            cout << "\nEnter Correct choice : ";
            break;
        }
    } while (option != 0);
    return 0;
}