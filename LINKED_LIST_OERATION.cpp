// DHIRAJ LAXMAN DARAKHE
// 21118 (com)
// PICT, PUNE


#include <bits/stdc++.h>
using namespace std;
int isSumEven(int a)
{
    int num = 0, m = 0, sum = 0;
    while (a > 0)
    {
        m = a % 10;
        sum = sum + m;
        a = a / 10;
    }
    if (sum % 2 == 0)
    {
        return 0;
    }
    return 1;
};
bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}
class Node
{
private:
    int data;
    Node *next;

public:
    friend class linked_list;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int a)
    {
        data = a;
        next = NULL;
    }
} *head = NULL;
class linked_list
{
    Node *temp;

public:
    linked_list()
    {
        head = NULL;
        temp = NULL;
    }
    void insert_node_at_end(int dt)
    {
        Node *new_node = new Node(dt);
        if (head == NULL)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    void insert_node_at_begin(int dt)
    {
        Node *new_node = new Node(dt);
        if (head == NULL)
        {
            head = temp = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }
    void delete_node(int dt)
    {
        Node *p = head;
        Node *b = head;
        while (p->data != dt)
        {
            b = p;
            p = p->next;
        }

        if (p == head)
        {
            head = p->next;
        }
        else
        {
            b->next = p->next;
        }
        p->data = 0;
        p = NULL;
        delete p;
    }

    void display()
    {
        Node *q = head;
        while (q != NULL)
        {
            cout << "| " << q->data;
            q = q->next;
            if (q != NULL)
            {
                cout << " | --> ";
            }
            else
            {
                cout << " |";
            }
        }
    }
    void addition_odd_place()
    {
        Node *q = head;
        int i = 1, sum = 0;
        while (q != NULL)
        {
            if (i % 2 != 0)
            {
                cout << "| " << q->data << " | --> ";
                sum += q->data;
            }
            q = q->next;
            i++;
        }
        cout << sum;
        cout << "\n";
    }
    void addition_even_place()
    {
        Node *q = head;
        int i = 1, sum = 0;
        while (q != NULL)
        {
            if (i % 2 == 0)
            {
                cout << "| " << q->data << " | --> ";
                sum += q->data;
            }
            q = q->next;
            i++;
        }
        cout << sum << "\n";
    }
    void addition_of_prime()
    {
        Node *q = head;
        int sum = 0;
        while (q != NULL)
        {
            if (isPrime(q->data))
            {
                cout << "| " << q->data << " | --> ";
                sum += q->data;
            }
            q = q->next;
        }
        cout << sum << "\n";
    }
    void delete_odd_prime()
    {
        Node *q = head;
        int sum = 0;
        while (q != NULL)
        {

            if (isPrime(q->data) && q->data % 2 != 0)
            {
                cout << "\ndeleted Data : ";
                cout << "| " << q->data << " |  ";
                delete_node(q->data);
            }
            q = q->next;
        }
        cout << "\n\n";
        display();
    }
};

int main()
{
    linked_list l1;
    cout << "\nEnter the size : ";
    int size;
    cin >> size;
    int a;
    while (size--)
    {
        cout << "\nEnter the number : ";
        cin >> a;
        if (isSumEven(a))
        {
            l1.insert_node_at_begin(a);
            // cout << 1 << endl;
        }
        else
        {
            l1.insert_node_at_end(a);
            // cout << 0 << endl;
        }
    }
    cout << "\n\n";
    cout << "\nLinked List                   : ";
    l1.display();
    cout << "\n\n";
    cout << "\nAddition of odd places data   : ";
    l1.addition_odd_place();
    cout << "\nAddition of even places data  : ";
    l1.addition_even_place();
    cout << "\nAdditon of the prime number   : ";
    l1.addition_of_prime();
    cout << "\nDelete the odd_prime data from linked list ";
    l1.delete_odd_prime();
    return 0;
}