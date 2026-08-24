class Solution {
    public:
    
        
    
        vector<int> diffWaysToCompute(string expression) {
            
            if(expression.length()==1 || (expression.length()==2 && expression[1]!='-' && expression[1]!='+' && expression[1]!='*')) {
                int x= stoi(expression);
                return {x};
            }
    
            vector<int> ans;
            for(int i=0;i<expression.length();i++){
                if(expression[i]!='-' && expression[i]!='+' && expression[i]!='*') continue;
                string s_l = expression.substr(0, i);
                string r_l = expression.substr(i+1, expression.length()-i-1);
    
                vector<int> left_evl = diffWaysToCompute(s_l);
                vector<int> right_evl = diffWaysToCompute(r_l);
    
                for(int l=0;l<left_evl.size();l++){
                    for(int r=0;r<right_evl.size();r++){
                        int l_n = left_evl[l];
                        int r_n = right_evl[r];
                        if(expression[i]=='-')
                        ans.push_back(l_n - r_n);
                        else if(expression[i]=='+') ans.push_back(l_n + r_n);
                        else if(expression[i]=='*') ans.push_back(l_n * r_n);
                     }
                }
                // return ans;
            }   
            return ans; 
        }
    };