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
    ListNode* reversek(ListNode* head, int k){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;
        while(k--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode* p1 = head;
        ListNode* prevtail = nullptr;
        ListNode* newhead = head;

        while(p1){
            ListNode* p2 = p1;
            int temp = k;

            while(temp > 1 && p2){
                p2 = p2->next;
                temp--;
            }
            if(!p2) break;
            ListNode* nextgrp = p2->next;
            p2->next = nullptr;

            ListNode* start = reversek(p1, k);

            if(prevtail){
                prevtail->next = start;
            }
            else{
                newhead = start;
            }
            p1->next = nextgrp;
            prevtail = p1;
            p1 = nextgrp;
        }
        return newhead;

    }
};
