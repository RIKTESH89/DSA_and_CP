class Solution {
    public:
    
      void rec(int ind, string& s, string temp, vector<string>& ans){
          if(ind == s.length()){
              if(temp[temp.length()-1]==' ') temp.pop_back();
              ans.push_back(temp); return;
          }
          
          
          rec(ind+1, s, temp + " " + s[ind], ans);
          rec(ind+1, s, temp + s[ind], ans);
          // return;
      }
    
      vector<string> permutation(string s) {
          // code here
          vector<string> ans;
          string temp = "";
          temp.push_back(s[0]);
          rec(1,s,temp,ans);
          return ans;
      }
  };