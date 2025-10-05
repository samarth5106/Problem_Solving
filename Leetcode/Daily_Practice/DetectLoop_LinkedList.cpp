class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> mp;
        ListNode* temp=head;
        while(temp){
            if(mp.find(temp)!=mp.end()){
                return true;
            }    
            mp[temp]=1;
            temp=temp->next;    
        }
        return false;
    }
};

