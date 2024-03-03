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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t = head, *h = head, *prev = nullptr;
        while(h){
            h = h->next;
            if(n <= 0){
                prev = t;
                t = t->next;
            }
            n--;
        }
        if(!prev)return head->next;
        prev -> next = prev->next->next;
        return head;
    }
};