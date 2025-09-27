class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
    int ops = 0;
    vector<int> flipped(n, 0);
    int currentFlips = 0;
    
    for(int i = 0; i < n; i++) {
        if(i >= k) {
            currentFlips -= flipped[i - k];
        }
        
        int currentValue = (arr[i] + currentFlips) % 2;
        
        if(currentValue == 0) {
            if(i + k > n) return -1;
            
            flipped[i] = 1;
            currentFlips++;
            ops++;
        }
    }
    
    return ops;
    }
};
