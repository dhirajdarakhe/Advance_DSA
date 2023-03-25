/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)  return nullptr;
        if(head==head->next) return head;
        if(head->next==nullptr) return nullptr;
        map<ListNode* , int> mp;
        while(head)
        {
            mp[head]++;
            if(mp.find(head->next) == mp.end())
               head = head->next;
            else 
                return head->next;
        }
        return nullptr;
        
    }
};