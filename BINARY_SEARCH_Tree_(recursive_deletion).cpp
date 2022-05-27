// DHIRAJ LAXMAN DARAKHE
// 21118 (com)
// PICT, PUNE


#include <bits/stdc++.h>
using namespace std;
class Node
{
    string word;
    string meaning;
    Node *lnext, *rnext;
    Node()
    {
        word = "";
        meaning = "";
        lnext = rnext = NULL;
    }
    friend class BinarySearchAlgo;
};
class BinarySearchAlgo
{
    Node *root;

public:
    BinarySearchAlgo()
    {
        root = NULL;
    }
    void CreateRootNode()
    {
        string w;
        string m;
        cout << "\nEnter the word : ";
        cin >> w;
        cout << "\nEnter the maning of the word : ";
        cin >> m;
        Insert(w, m);
        cout << "\nRootnode is successfully Created \n";
    }
    void Insert(string w, string m)
    {
        Node *temp = new Node;
        temp->word = w;
        temp->meaning = m;
        temp->lnext = temp->rnext = NULL;
        if (root == NULL)
        {
            root = temp;
            return;
        }
        else
        {
            Node *pare;
            Node *rtemp = root;
            while (1)
            {
                pare = rtemp;
                if (w == rtemp->word)
                {
                    cout << "\nDublicate word !!!! ";
                    return;
                }
                if (w < rtemp->word)
                {
                    rtemp = rtemp->lnext;
                }
                else if (w > rtemp->word)
                {
                    rtemp = rtemp->rnext;
                }
                if (rtemp == NULL)
                {
                    if (w < pare->word)
                    {
                        pare->lnext = temp;
                    }
                    else
                    {
                        pare->rnext = temp;
                    }
                    cout << "\nNew Node is succussfully added\n";
                    return;
                }
            }
        }
    }
    void Inorder()
    {
        Inorder(root);
    }
    void Inorder(Node *r)
    {
        Node *rtemp = r;
        if (r == NULL)
        {
            return;
        }
        Inorder(r->lnext);
        cout << "\nword : " << r->word << "  |  meaning :  " << r->meaning;
        Inorder(r->rnext);
    }
    void Update(string updateWord)
    {
        Node *rtemp = root;
        if (rtemp->word == updateWord)
        {
            string s1, s2;
            cout << "\n Enter the meaning of " << s1 << " for updation :  ";
            // cin >> s1;
            cin >> s2;
            // rtemp->word = s1;
            rtemp->meaning = s2;
            return;
        }
        else
        {
            // Node *pare;
            while (1)
            {
                // pare = rtemp;
                if (updateWord < rtemp->word)
                {
                    rtemp = rtemp->lnext;
                }
                else if (updateWord > rtemp->word)
                {
                    rtemp = rtemp->rnext;
                }
                if (rtemp == NULL)
                {
                    cout << "\n Sorry , Entered word is not found ";
                    return;
                }
                if (rtemp->word == updateWord)
                {
                    string s1, s2;
                    cout << "\n Enter the new word and meaning which you want to Insert ";
                    cin >> s1;
                    cin >> s2;
                    rtemp->word = s1;
                    rtemp->meaning = s2;
                    return;
                }
            }
        }
    }
    void Delete(string s)
    {
        root = Delete(root, s);
    }
    Node *Delete(Node *root, string key)
    {
        if (root == NULL)
            return root;
        else if (root->word > key)
        {
            root->lnext = Delete(root->lnext, key);
        }
        else if (root->word < key)
        {
            root->rnext = Delete(root->rnext, key);
        }
        else
        {
            if ((root->lnext == NULL) && (root->rnext == NULL))
            {
                delete root;
                root = NULL;
                return root;
            }
            else if (root->lnext == NULL)
            {
                Node *temp = root->rnext;
                delete root;
                return temp;
            }
            else if (root->rnext == NULL)
            {
                Node *temp = root->lnext;
                delete root;
                return temp;
            }
            else
            {
                Node *temp = FindMin(root->rnext);
                root->word = temp->word;
                root->meaning = temp->meaning;
                root->rnext = Delete(root->rnext, temp->word);
            }
        }
        return root;
    }
    Node *FindMin(Node *temp)
    {
        while (temp->lnext)
        {
            temp = temp->lnext;
        }
        return temp;
    }
};
int main()
{
    BinarySearchAlgo obj;
    obj.CreateRootNode();
    for (int i = 0; i < 4; i++)
    {
        string w;
        string m;
        cout << "\nEnter the word : ";
        cin >> w;
        cout << "\nEnter the maning of the word : ";
        cin >> m;
        obj.Insert(w, m);
    }

    cout << "\nDo you want to continue (y/n) ";
    char c;
    cin >> c;
    if (c == 'n')
        return 0;
    // obj.Insert("E", "6");
    // obj.Insert("D", "4");
    // obj.Insert("C", "3");
    obj.Inorder();
    string k;
    cout << "\nEnter the word to be deleted";
    cin >> k;
    obj.Delete(k);
    obj.Inorder();
    // string k;
    cout << "\nEnter the word to be deleted";
    cin >> k;
    obj.Delete(k);
    obj.Inorder();
    // string k;
    cout << "\nEnter the word to be deleted";
    cin >> k;
    obj.Delete(k);
    obj.Inorder();
    cout << "\nDo you want to continue (y/n) ";
    // char c;
    cin >> c;
    if (c == 'n')
        return 0;
    string s;
    cout << "\nEnter the word to be updated";
    cin >> s;
    obj.Update(s);
    obj.Inorder();
    return 0;
}
