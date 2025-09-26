class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int cnt = 0;
        
        for(int k = 2; k < n; k++) {
            int left = 0, right = k - 1;
            
            while(left < right) {
                if(arr[left] + arr[right] > arr[k]) {
                    cnt += right - left;
                    right--;
                } else {
                    left++;
                }
            }
        }
        
        return cnt;
    }
};
