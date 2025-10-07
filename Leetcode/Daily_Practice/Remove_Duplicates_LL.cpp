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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        if(temp==NULL||temp->next==NULL){
            return head;
        }
        ListNode* nextNode=temp->next;
        while(temp&&nextNode){
            if(temp->val!=nextNode->val){
                temp->next=nextNode;
                temp=temp->next;
                nextNode=nextNode->next;
            }
            else{
                while(nextNode!=NULL&&nextNode->val==temp->val){
                    nextNode=nextNode->next;
                }
                temp->next=nextNode;
                temp=temp->next;
                if(nextNode)
                nextNode=nextNode->next;
            }
        }
        return head;
        
    }
};
