// DHIRAJ LAXMAN DARAKHE
// 21118 (com)
// PICT, PUNE


#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
class node
{
    string word, meaning;
    node *next;

public:
    node()
    {
        word = meaning = "None";
        next = NULL;
    }
    node(string w, string m)
    {
        word = w;
        meaning = m;
        next = NULL;
    }

    friend class HashEntry;
};
class HashEntry
{
    node *head;

public:
    HashEntry()
    {
        head = NULL;
    }
    void Insert(string w, string m)
    {

        if (head)
        {
            node *temp = head;
            while (temp->next && temp->word != w)
            {
                temp = temp->next;
            }
            if (temp->word == w)
            {
                cout << "\nDublicate Entry : ";
                return;
            }
            node *new_node = new node(w, m);
            temp->next = new_node;
            return;
        }
        else
        {
            node *new_node = new node(w, m);
            head = new_node;
            return;
        }
    }
    void Remove(string w)
    {
        if (head)
        {
            if (head->word == w)
            {
                node *temp = head;
                head = head->next;
                delete temp;
                return;
            }
            node *pare = head;
            node *child = head->next;
            while (child)
            {
                if (child->word == w)
                {
                    pare->next = child->next;
                    delete child;
                    cout << "\nEntry sucessfull delted  : ";
                    return;
                }
                else
                {
                    pare = pare->next;
                    child = child->next;
                }
            }
            cout << "\nEntry is not present : ";
            return;
        }
        else
        {
            cout << "\nEntry is not present : ";
        }
    }
    bool find(string w)
    {
        if (head)
        {
            node *temp = head;
            while (temp)
            {
                if (temp->word == w)
                {
                    cout << "\nFound : ";
                    cout << temp->word << " " << temp->meaning << endl;
                    return 1;
                }
                temp = temp->next;
            }
            cout << "\nSorry Entry is not 4present : ";
            return 0;
        }
        else
        {
            cout << "\nSorry Entry is not present : ";
            return 0;
        }
    }
    void print()
    {
        node *temp = head;
        if (temp)
        {
            while (temp)
            {
                cout << " [ " << temp->word << " " << temp->meaning << " ] "
                     << " > ";
                ;
                temp = temp->next;
            }
            return;
        }
        else
        {
            cout << " - ";
            cout << endl;
        }
    }
};
class HashTable
{
    HashEntry *table;

public:
    HashTable()
    {
        table = new HashEntry[SIZE];
    }
    int location(string s1)
    {
        return s1[0] % SIZE;
    }
    void Insert()
    {
        for (int i = 0; i < SIZE; i++)
        {
            string s1, s2;
            cout << "\nEnter the word and it's meaning : ";
            cin >> s1 >> s2;
            int index = location(s1);
            table[index].Insert(s1, s2);
            cout << "\nDo u wanna conti : ";
            int t;
            cin >> t;
            if (t == 1)
            {
                break;
                ;
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            cout << endl
                 << i << " ) ";
            table[i].print();
        }
        for (int i = 0; i < SIZE; i++)
        {
            string s;
            cout << "\nEnter the string to find : ";
            cin >> s;
            int t = location(s);
            cout << table[t].find(s);
            cout << "\nDo u wanna conti : ";
            int t1;
            cin >> t1;
            if (t1 == 1)
            {
                break;
                ;
            }
        }
    }
};
int main()
{
    HashTable hs;
    hs.Insert();
    return 0;
}