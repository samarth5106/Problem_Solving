class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        int n=dq.size();
        vector<int> vec;
      k=k%n;
      if(k==0)
      return;
      
        if(type==1){
            for(int i=n-k;i<n;i++){
                vec.push_back(dq[i]);
           
            }
            for(int i=0;i<n-k;i++){
                vec.push_back(dq[i]);
            }
            
            
        }
        else{
            for(int i=k;i<n;i++){
                vec.push_back(dq[i]);
            }
            for(int i=0;i<k;i++){
                vec.push_back(dq[i]);
            }
            
        }
        dq.clear();
        for(int i=0;i<n;i++){
                dq.push_back(vec[i]);
            }
        
    }
};
