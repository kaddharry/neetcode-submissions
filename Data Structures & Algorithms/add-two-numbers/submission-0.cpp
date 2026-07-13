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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        while (l1 && l2) {
            int x = l1->val + l2->val + carry;
            carry = x / 10;
            curr->next = new ListNode(x % 10);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* rem = (l1 ? l1 : l2);
        while (rem) {
            int x = rem->val + carry;
            curr->next = new ListNode(x % 10);
            curr = curr->next;
            carry = x / 10;
            rem = rem->next;
        }
        if (carry) curr->next = new ListNode(carry);
        return dummy->next;
    }
};
