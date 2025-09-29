class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        vector<long long> prefix(n + 1, 0);
 
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        long long maxi = LLONG_MIN;
        deque<int> dq;
        for(int i = a; i <= n; i++) {
            while(!dq.empty() && dq.front() < i - b) {
                dq.pop_front();
            }
            if(i - a >= 0) {
                while(!dq.empty() && prefix[dq.back()] >= prefix[i - a]) {
                    dq.pop_back();
                }
                dq.push_back(i - a);
            }
            if(!dq.empty()) {
                maxi = max(maxi, prefix[i] - prefix[dq.front()]);
            }
        }
        
        return (int)maxi;
    }
};
