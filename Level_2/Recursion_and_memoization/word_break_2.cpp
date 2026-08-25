class Solution {
    public:
    
        bool isvalid(string str, vector<string>& wordDict){
            for(auto it:wordDict){
                if(it == str) return true;
            }
            return false;
        }
    
        void rec(int ind, vector<string>& wordDict, string s, vector<string>& ans, vector<string>& temp){
            if(ind == s.length()){
                string str = "";
                for(int it = 0;it<temp.size()-1;it++) str += temp[it] + " ";
                str+=temp[temp.size()-1];
                ans.push_back(str);
                return;
            }
    
            for(int i=ind;i<s.length();i++){
                string str = s.substr(ind, i-ind+1);
                if(isvalid(str,wordDict)){
                    temp.push_back(str);
                    rec(i+1, wordDict, s, ans, temp);
                    temp.pop_back();
                }
            }
            return;
    
        }
    
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            vector<string> ans;
            vector<string> temp;
            rec(0,wordDict,s,ans, temp);
            return ans;
        }
    };