class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp1=head;
        vector<int> vec;
        while(temp1){
           vec.push_back(temp1->val);
           temp1=temp1->next;
        }
        int s=0,end=vec.size()-1;
        while(s<=end){
             if(vec[s] != vec[end]){
        return false;
    }
    s++;
    end--;
        }
        return true;
        
    }
};
