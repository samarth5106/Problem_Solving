class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorv=0;
        
        
        for(int i=0;i<nums.size();i++){
            xorv=xorv^nums[i];
        }
        if(xorv==0){
            return nums.size()-1;
        }
        else
            return nums.size();
    }
};
