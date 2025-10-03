 class Solution {
private:
const string unmp[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
    
  public:
  void solve(vector<int> &arr,vector<string>&result,string &current,int i){
      if(i==arr.size()){
          if(current.empty()==false){
              result.push_back(current);
             
          }
           return ;
      }
      int digit=arr[i];
      if(digit<=1){
      solve(arr,result,current,i+1);
      return;
      }   
      string word=unmp[digit];
      for(char c:word){
          current.push_back(c);
          solve(arr,result,current,i+1);
          current.pop_back();
      }
  }
  
  
  
  
    vector<string> possibleWords(vector<int> &arr) {
        // code here
         vector<string> result;
         string current="";
         solve(arr,result,current,0);
         return result;
        
    }
};
