class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long k=n;
        int cnt=0;
        while(k>0){
            //k=%10;
            k=k/10;
            cnt++;
        }
        k=n;
        int nu=1;
        long long val=1;
        while(nu<=cnt){
            int mod=k%10;
            if(mod==0){
                nu++;
            val=val*10;
            k=k/10;
                continue;
            }
            ans.push_back(mod*val);
            nu++;
            val=val*10;
            k=k/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
