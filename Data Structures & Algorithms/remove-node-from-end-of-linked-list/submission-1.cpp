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
        int k = 0;
        ListNode* p = head;
        while(p){
            p = p->next;
            k++;
        }
        p = head;
        k -= n;
        if(k == 0){
            return head->next;
        }
        k--;
        while(k){
            p = p->next;
            k--;
        }
        p->next = p->next->next;
        return head;
    }
};
