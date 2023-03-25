// https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292?leftPanelTab=1
#include <bits/stdc++.h>
class Node
{
public:
    Node *link[26];
    Node()
    {
        for (int i = 0; i < 26; ++i)
            link[i] = NULL;
    }
    void put(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }
    Node *getReference(char ch)
    {
        return link[ch - 'a'];
    }
    bool containKey(char ch)
    {
        return link[ch - 'a'] != NULL;
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
    int insert(string &word)
    {
        int count = 0;
      
        for(int j = 0 ; j < word.size(); ++j)
        {
            Node *node = root;
            for(int i = j; i < word.size(); ++i)
            {
                if (!node->containKey(word[i]))
                {
                    node->put(word[i], new Node());
                    count++;
                }
                node = node->getReference(word[i]);
            }
        }
        return ++count;  
    }
};
int countDistinctSubstrings(string &s)
{
   Trie T;
   return T.insert(s);
}
