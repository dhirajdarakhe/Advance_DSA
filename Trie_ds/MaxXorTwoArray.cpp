// https://www.codingninjas.com/codestudio/problems/maximum-xor_3119012?topList=striver-sde-sheet-problems&leftPanelTab=0
#include <bits/stdc++.h> 
class Node
{
    Node *list[2];
    public:
    Node()
    {
        list[0] = NULL;
        list[1] = NULL;
    }
    Node *get(int bit)
    {
        return list[bit];
    }
    void put(int bit, Node* new_node)
    {
        list[bit] = new_node;
    }
    bool containKey(int bit)
    {
        return (list[bit] != NULL);
    }
};
class Trie
{
    Node * root;
    public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        // cout<<num<<" \ ";
        Node * temp = root;
        for(int i = 31; i >= 0; --i)
        {
            int bit = ((num>>i)&1);
            if(!temp->containKey(bit))
            {
                temp->put(bit, new Node());
            }
            temp = temp->get(bit);
        }
    }
     
    int findmax(int num)
    {
        int ans = 0;
        Node * temp = root;
        for(int i = 31;i >= 0; --i)
        {
            int bit = ( (num>>i) & 1 );
            if(temp->containKey(!bit))
            {
                ans = (ans | (1<<i));
                temp= temp->get(!bit);
            }
            else
            {
                temp = temp->get(bit);
            }
        }
        // cout<<ans<<" ";
        return ans;
    }
};

int maximumXor(vector<int> A)
{
    // Write your code here.
    Trie t;
    for(int i = 0 ; i < A.size(); ++i) t.insert(A[i]);
    int mx = 0;
    for(int i =0; i < A.size(); ++i) mx = max(mx, t.findmax(A[i]));
    return mx;
}
