class Solution {
    public:
    
        void rec(int i, string temp, vector<string>& ans, string digits, vector<string>& alpha){
    
            if(temp.size() == digits.size()){
                ans.push_back(temp);
                return;
            }
    
            string letters = alpha[digits[i]-'0'];
            for(auto it: letters){
                temp.push_back(it);
                rec(i+1, temp,ans,digits,alpha);
                temp.pop_back();
            }
            return;
        }
    
        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            vector<string> alpha = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            rec(0,"",ans,digits,alpha);
            return ans;
        }
    };