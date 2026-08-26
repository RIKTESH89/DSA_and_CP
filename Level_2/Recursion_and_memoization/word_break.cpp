class Solution {
    public:
    
        bool isvalid(string s, vector<string>& wordDict){
            for(auto it: wordDict) if(s == it) return true;
    
            return false;
        }
    
        bool rec(int ind,string s, vector<string>& wordDict, vector<int>& dp){
            if(ind == s.length()) return true;
    
            if(dp[ind] == 1) return true;
            if(dp[ind] == 2) return false;
            
            for(int i=ind;i<s.length();i++){
                string str = s.substr(ind, i-ind+1);
                if(isvalid(str,wordDict)){
                    if(rec(i+1, s, wordDict,dp)) {
                        dp[ind] = 1;
                        return true;
                    }
                }
            }
            dp[ind] = 2;
            return false;
        }
    
        bool wordBreak(string s, vector<string>& wordDict) {
            vector<int> dp(301,-1);
            return rec(0,s,wordDict,dp);
        }
    };