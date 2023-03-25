/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int n = 0;
        ListNode *temp = head;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        // cout<<n<<" " << k <<" " << k %n<<endl;
        n = k % n;
        temp = head;
        while(temp&&n--) temp=temp->next;
        ListNode *node = head;
        if(temp==nullptr) return head;
        while(temp->next)
        {
            temp=temp->next;
            node=node->next;
        }
        temp->next=head;
        temp= node->next;
        node->next=nullptr;
        return temp;
    }
};