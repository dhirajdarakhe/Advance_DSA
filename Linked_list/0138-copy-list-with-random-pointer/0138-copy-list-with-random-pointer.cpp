/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        if (head == NULL)
            return head;
        Node *it = head;
        Node *nxt;
        while (it != NULL)
        {
            nxt = it->next;
            Node *node = new Node (it->val);
            it->next = node;
            node->next = nxt;
            it = nxt;
        }

        it = head;
        while (it != NULL)
        {
            if (it->random != NULL)
                it->next->random = it->random->next;
            it = it->next->next;
        }

        it = head;
        Node *copy, *curr, *dummy = new Node(0);
        curr = dummy;

        while (it != NULL)
        {
            nxt = it->next->next;
            copy = it->next;
            curr->next = copy;
            curr = copy;
            //    nxt = copy->next;
            it->next = nxt;
            it = nxt;
        }
        return dummy->next;
    }
};