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
        ListNode* slow = head;
        // ListNode* fast = head;
        int k = 1;
        while (slow->next != NULL) {
            slow = slow->next;
            k++;
        }
        if (k == n) {
            head = head->next;
            return head;
        } else if (k == 1 && n == 1) {
            return NULL;
        } else {
            slow = head;
            int c = k - n - 1;
            while (c != 0) {
                slow = slow->next;
                c--;
            }
            slow->next = slow->next->next;
        }
        return head;
    }
};