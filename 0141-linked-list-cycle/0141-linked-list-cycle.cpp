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
    bool hasCycle(ListNode *head) {
        ListNode* t = head,*h=head;
        while(h && h->next){
            t = t->next;
            h = h->next->next;
            if(t == h)return 1;
        }
        return 0;
    }
};