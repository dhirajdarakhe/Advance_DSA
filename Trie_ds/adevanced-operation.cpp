https://www.codingninjas.com/codestudio/problems/implement-trie_1387095
#include <bits/stdc++.h>
class Node
{
public:
    Node *link[26];
    int ctend;
    int ctpre;
    Node()
    {
        for (int i = 0; i < 26; ++i)
            link[i] = NULL;
        ctend = 0;
        ctpre = 0;
    }
    //  add reference trie
    void put(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }
    // get Reference
    Node *getReference(char ch)
    {
        return link[ch - 'a'];
    }
    //  to check the char is present or not
    bool containKey(char ch)
    {
        // return 1 if it is there
        // else return 0
        return link[ch - 'a'] != NULL;
    }
    int getend() { return ctend; }
    int getpre() { return ctpre; }
    void incend() { ctend++; }
    void incpre() { ctpre++; }
    void decend() { ctend--; }
    void decpre() { ctpre--; }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            // insert if ref trie node is not present
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // get prefix reference
            node = node->getReference(word[i]);
            // increse the prx
            node->incpre();
        }
        // increase the ctend
        node->incend();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            // get next ref trie if ref trie node is present
            if (node->containKey(word[i]))
            {
                node = node->getReference(word[i]);
            }
            // else rweturn 0;
            else
            {
                return 0;
            }
        }
        return node->getend();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            // get next ref trie if ref trie node is present
            if (node->containKey(word[i]))
            {
                node = node->getReference(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getpre();
    }

    void erase(string &word)
    {
        // firstly check word is present or not
        if (countWordsEqualTo(word) == 0)
            return;
        Node *node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            node = node->getReference(word[i]);
            node->decpre();
        }
        node->decend();
    }
};
