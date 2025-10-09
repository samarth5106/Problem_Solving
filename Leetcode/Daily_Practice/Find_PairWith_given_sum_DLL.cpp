class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        // Your code goes here
        unordered_map<int,int> unmp;
        ListNode* temp=head;
        while(temp){
            unmp[temp->val]=1;
            temp=temp->next;
        }
        temp=head;
        int diff;
        vector<vector<int>> ans;
        while(temp){
            diff=target-temp->val;
            if(diff<temp->val||diff==temp->val){
                temp=temp->next;
                continue;
            }
            else{
                if(unmp.find(diff)!=unmp.end()){
                    vector<int> to;
                    to.push_back(temp->val);
                    to.push_back(diff);
                    ans.push_back(to);
                }
                }
                temp=temp->next;
            }
         return ans;   
        }
    };
