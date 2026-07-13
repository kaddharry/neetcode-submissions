/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* tail = &dummy;
        Node* p = head;
        while (p) {
            int z = p->val;
            tail->next = new Node(z);
            tail = tail->next;
            tail->random = p->random;
            p = p->next;
        }
        tail = dummy.next;
        while (tail) {
            p = head;
            int counter = 0;
            while (tail->random != p) {
                if (!p) break;
                p = p->next;
                counter++;
            }
            if (!p)
                tail->random = NULL;
            else {
                Node* temp = dummy.next;
                while (counter) {
                    temp = temp->next;
                    counter--;
                }
                tail->random = temp;
            }
            tail = tail->next;
        }
        return dummy.next;
    }
};
