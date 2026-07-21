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
    ListNode* cur;
    bool rec(ListNode* head) {
        if (head) {
            if (!rec(head->next)) {
                return false;
            }
            if (head->val != cur->val) {
                return false;
            }
            cur = cur->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        cur = head;
        return rec(head);
    }
};