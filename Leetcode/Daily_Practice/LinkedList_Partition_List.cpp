class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        queue<ListNode*> smaller;
        queue<ListNode*> greaterEqual;
        
        ListNode* temp = head;
        
        while(temp) {
            if(temp->val < x) {
                smaller.push(temp);
            } else {
                greaterEqual.push(temp);
            }
            temp = temp->next;
        }
        
        if(smaller.empty()) return head;
        
        head = smaller.front();
        smaller.pop();
        temp = head;
        
        while(!smaller.empty()) {
            temp->next = smaller.front();
            smaller.pop();
            temp = temp->next;
        }
        
        while(!greaterEqual.empty()) {
            temp->next = greaterEqual.front();
            greaterEqual.pop();
            temp = temp->next;
        }
        
        temp->next = nullptr;
        
        return head;
    }
};
