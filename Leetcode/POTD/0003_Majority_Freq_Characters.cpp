class Solution {
public:
    string majorityFrequencyGroup(string s) {
        map<char,int> mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
        }
        
        map<int, vector<char>> groups;
        for(auto& p : mp) {
            groups[p.second].push_back(p.first);
        }
        int maxi = 0;
        int bestfreq = 0;
        for(auto& p : groups) {
            int freq = p.first;
            int size = p.second.size();
            if(size>maxi||(size==maxi && freq>bestfreq)) {
                maxi=size;
                bestfreq=freq;
            }
        }
        string result = "";
        for(char c : groups[bestfreq]) {
            result += c;
        }
        return result;
    }
};
