#include <bits/stdc++.h>
using namespace std;
#define ll long long
int charPos(char ch)
{
    return (int)(ch - 'a');
}
class Node
{
private:
    Node *link[26];
    bool flag;

public:
    Node()
    {
        for (int i = 0; i < 26; ++i)
            link[i] = NULL;
        flag = 0;
    }
    bool isKeyPresent(char ch)
    {

        // return 1 -> if ch is present
        // return 0 -> else ch is not there
        return link[charPos(ch)] != NULL;
    }

    // return referenceTrie node;
    Node *referenceTrie(int ch)
    {
        return link[charPos(ch)];
    }
    // add new trie node
    void addTrie(char ch, Node *new_node)
    {
        link[charPos(ch)] = new_node;
    }
    // set flag true;
    void setflagTrue()
    {
        flag = 1;
    }
    // get flag;
    bool getflag()
    {
        return flag;
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            // if current char is no present
            // then add it in tree
            if (!node->isKeyPresent(word[i]))
            {
                node->addTrie(word[i], new Node());
            }
            //  move to the corresponding reference trie node
            node = node->referenceTrie(word[i]);
        }
        // set flag True
        node->setflagTrue();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            // if current char is no present
            if (!node->isKeyPresent(word[i]))
            {
                return 0;
            }
            //  move to the corresponding reference trie node
            node = node->referenceTrie(word[i]);
        }
        // return last node flag
        return node->getflag();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            // if current char is no present
            if (!node->isKeyPresent(prefix[i]))
            {
                return 0;
            }
            //  move to the corresponding reference trie node
            node = node->referenceTrie(prefix[i]);
        }
        // prefix found
        return 1;
    }
};

int main()
{
    Trie T;
    while (1)
    {
        char x;
        int op = 1;
        cout << "Enter y / n : ";
        cin >> x;
        if (x == 'n' || x == 'N')
            return 0;
        cout << "Op 1 ) insert 2) Serach 3) Prefix : ";
        cin >> op;
        string s;
        cout << "Enter the string : ";
        cin >> s;
        if (op == 1)
        {
            T.insert(s);
        }
        else if (op == 2)
        {
            cout << T.search(s);
        }
        else if (op == 3)
        {
            cout << T.startsWith(s);
        }
        else
        {
            cout << "Enter corect choice:";
        }
        cout << endl;
    }
    return 0;
}

// input
// [ "Trie", "insert", "search", "search", "startsWith", "insert", "search" ];
// [ [], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"] ];
// output
// [null,null,true,false,true,null,true]


// Enter y / n : y
// Op 1 ) insert 2) Serach 3) Prefix : 1
// Enter the string : dhiraj

// Enter y / n : y
// Op 1 ) insert 2) Serach 3) Prefix : 2
// Enter the string : dhixaj
// 0
// Enter y / n : y
// Op 1 ) insert 2) Serach 3) Prefix : 3
// Enter the string : dhir
// 1
// Enter y / n : n
