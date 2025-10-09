class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front = temp->next;

        if (head->val == target) {
            while (head && head->val == target) {
                temp = head;
                head = head->next;
                delete temp;
                if (head) head->prev = NULL;
            }
            if (!head) return NULL;
        }

        temp = head;
        prev = NULL;
        front = temp->next;

        while (front) {
            if (temp->val == target) {
                if (prev != NULL) {
                    prev->next = front;
                }
                ListNode* del = temp;
                temp = front;
                front->prev = prev;
                front = front->next;
                delete del;
            }
            else {
                prev = temp;
                temp = front;
                front = front->next;
            }
        }

        if (temp->val == target) {
            prev->next = NULL;
            delete temp;
        }

        return head;
    }
};
