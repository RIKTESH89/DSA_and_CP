class Solution {
    public:
    
        void rec(int i, int j, int n, vector<string>& ans, string temp){
            if(i>n || j>n) return;
            if(i==n && j==n){
                ans.push_back(temp); return;
            }
            
            if(i<n){
                temp.push_back('(');
                rec(i+1,j,n,ans,temp);
                temp.pop_back();
            }
            if(j<i){
                temp.push_back(')');
                rec(i,j+1,n,ans,temp);
                temp.pop_back();
            }
            return;
        }
    
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            string temp = "";
            rec(0,0,n,ans,temp);
            return ans;
        }
    };