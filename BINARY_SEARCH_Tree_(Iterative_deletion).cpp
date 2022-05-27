// DHIRAJ LAXMAN DARAKHE
// 21118 (com)
// PICT, PUNE


#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node *left;
    Node *right;
    Node()
    {
        data = "";
        left = right = NULL;
    }
};
class binarysearchtree
{
    Node *root;

public:
    binarysearchtree()
    {
        root = new Node;
    }
    Node *Create_binarysearchtree(string key)
    {
        root->data = key;
        root->left = root->right = NULL;
        // insert (root, key);
        return root;
    }
    // iterative binary search tree
    void insert(Node *t, string key)
    {
        Node *p;
        Node *Temp = NULL;
        while (t)
        {
            if (t->data == key)
            {
                cout << "\nEnter data is already present, so Couldn't insert in Binary search tree \n";
                return;
            }
            else if (t->data > key)
            {
                Temp = t;
                t = t->left;
            }
            else
            {
                Temp = t;
                t = t->right;
            }
        }
        p = new Node;
        p->data = key;
        p->left = p->right = NULL;
        if (Temp != NULL)
        {
            if (Temp->data > key)
                Temp->left = p;
            else
                Temp->right = p;
        }
    }

    void InOrder(Node *Troot)
    {
        Node *p = Troot;
        if (p)
        {
            InOrder(p->left);
            cout << p->data << " ";
            InOrder(p->right);
        }
    }

    void Search_IN_BST(Node *t, string key)
    {

        while (t)
        {
            if (t->data == key)
            {
                cout << "\n"
                     << key << " is present Binary search tree \n";
                return;
            }
            else if (t->data > key)
            {
                t = t->left;
            }
            else
            {
                t = t->right;
            }
        }
        if (t == NULL)
        {
            cout << "\n"
                 << key << " is not present Binary search tree \n";
        }
    }

    int find_ele(Node *curr, string key)
    {
        Node *pare = NULL;
        while (curr != NULL && curr->data != key)
        {
            pare = curr;
            if (key < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        if (curr == NULL)
            return -1;
        return 1;
    }
    void delete_node(Node *root, string key)
    {
        Node *curr = NULL, *pare = NULL;
        curr = root;
        while (curr != NULL && curr->data != key)
        {
            pare = curr;
            if (key < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        if (curr == NULL)
        {
            cout << "Element not Found'\n";
            return;
        }
        // case : 01
        if (curr->left == NULL && curr->right == NULL)
        {
            if (curr != root)
            {
                if (pare->left == curr)
                {
                    pare->left == NULL;
                }
                else
                {
                    pare->right = NULL;
                }
            }
            else
            {
                root = NULL;
            }

            delete curr;
        }

        // case : 02

        else if (curr->left != NULL && curr->right != NULL)
        {
            Node *inOrder_Successor = curr->right;
            while (inOrder_Successor->left != NULL)
            {
                inOrder_Successor = inOrder_Successor->left;
            }
            string val = inOrder_Successor->data;
            delete_node(root, inOrder_Successor->data);
            curr->data = val;
        }

        // case : 03
        else
        {
            if (curr == root)
            {
                root = NULL;
            }
            else if (pare->left == curr)
            {
                if (curr->left)
                {
                    pare->left = curr->left;
                }
                else
                {
                    pare->left = curr->right;
                }
            }
            else
            {
                if (curr->left)
                {
                    pare->right = curr->left;
                }
                else
                {
                    pare->right = curr->right;
                }
            }
            delete curr;
        }
    }
};

int main()
{
    // CREATION
    cout << "\n\n\t **  CREATION of Binary search tree **\n";
    binarysearchtree b1;
    string ele = " ";
    cout << "\nEnter the root (string) data for binry search tree  > ";
    cin >> ele;
    Node *root1 = b1.Create_binarysearchtree(ele);
    while (1)
    {
        cout << "\nEnter the (string) data to insert in binry search tree ( enter 0 to stop taking an input)  > ";
        cin >> ele;
        if (ele == "0")
            break;
        b1.insert(root1, ele);
    }

    // INORDER TRAVERSAL
    cout << "\n\n\t  **  INORDER TRAVERSAL in Binary search tree **\n";
    // cout << "\nThe given input is string that why it orderd like that \n";
    cout<<">     [ ";
    b1.InOrder(root1);
    cout << "]\n";

    // SEARCHING
    cout << "\n\n\t  **  SEARCHING in Binary search tree \n";
    cout << "\nEnter data for searching \n";
    cin >> ele;
    b1.Search_IN_BST(root1, ele);
    cout << "\nEnter data for searching \n";
    cin >> ele;
    b1.Search_IN_BST(root1, ele);

    // DELETION
    cout << "\n\n\t  **  DELETION in Binary search tree \n";
    cout << "\nEnter data for deletion \n";
    cin >> ele;
    b1.delete_node(root1, ele);
    b1.InOrder(root1);
    cout << "Hello World";

    // // UPDATE
    cout << "\n\n\t  **  UPDATION in Binary search tree \n";
    cout << "\nWhich element you want to update in BST \n";
    cin >> ele;
    int hasElement = b1.find_ele(root1, ele);
    if (hasElement == 1)
    {
        b1.delete_node(root1, ele);
        cout << "\nWhich element you want to add in replacement of " << ele << " in BST \n ";
        cin >> ele;
        b1.insert(root1, ele);
        cout << "\nInorder Transversal of Binary search tree \n";
        b1.InOrder(root1);
        cout << "\n";
    }
    else
    {
        cout << "\nEntered element is not found in given binary search tree";
    }

    return 0;
}
