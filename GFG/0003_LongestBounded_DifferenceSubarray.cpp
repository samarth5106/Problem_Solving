class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int left = 0;
        int maxLen = 0;
        int start = 0, end = 0;
        
        deque<int> minDeque, maxDeque;
        
        for(int right = 0; right < n; right++) {
            while(!minDeque.empty() && arr[minDeque.back()] >= arr[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);
            
            while(!maxDeque.empty() && arr[maxDeque.back()] <= arr[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);
            
            while(left <= right && arr[maxDeque.front()] - arr[minDeque.front()] > x) {
                if(minDeque.front() == left) minDeque.pop_front();
                if(maxDeque.front() == left) maxDeque.pop_front();
                left++;
            }
            
            if(right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
                end = right;
            }
        }
        
        vector<int> result;
        for(int i = start; i <= end; i++) {
            result.push_back(arr[i]);
        }
        return result;
    }
};
