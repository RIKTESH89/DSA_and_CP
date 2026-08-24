class Solution {
    public:
    
        bool ispalindrome(string str){
            for(int i=0;i<str.length()/2;i++){
                if(str[i]!=str[str.length()-1-i]) return false;
            }
            return true;
        }
    
        void rec(int ind, string s, vector<string>& temp, vector<vector<string>>& ans){
            if(ind==s.length()) {
                ans.push_back(temp); return;
            }
    
            for(int i=ind;i<s.length();i++){
                string s1 = s.substr(ind, i-ind+1);
                if(ispalindrome(s1)){
                    temp.push_back(s1);
                    rec(i+1, s, temp, ans);
                    temp.pop_back();
                }
            }
            return;
        }
    
        vector<vector<string>> partition(string s) {
            vector<string> temp;
            vector<vector<string>> ans;
    
            rec(0,s,temp,ans);
            return ans;
        }
    };