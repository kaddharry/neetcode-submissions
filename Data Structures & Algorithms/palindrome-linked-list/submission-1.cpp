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
    ListNode* curr;
    bool rec(ListNode* node) {
        if (!node) return true;
        if (!rec(node->next)) return false;
        if (curr->val == node->val) {
            curr = curr->next;
            return true;
        }
        return false;
    }
    bool isPalindrome(ListNode* head) {
        curr = head;
        return rec(head);
    }
};