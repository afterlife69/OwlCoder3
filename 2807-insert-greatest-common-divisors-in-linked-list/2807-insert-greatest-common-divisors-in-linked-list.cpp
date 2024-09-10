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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode * t = head;
        while(t && t->next){
            ListNode * nn = new ListNode(__gcd(t->val,t->next->val));
            nn->next = t->next;
            t->next = nn;
            t = nn->next;
        }
        return head;
    }
};