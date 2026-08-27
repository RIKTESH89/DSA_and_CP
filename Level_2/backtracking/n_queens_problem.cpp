class Solution {
    public:
    
        bool isvalid(int n, int i, int j, vector<int>& row, vector<int>& col, vector<int>& p_d, vector<int>& s_d){
            if(row[i]==1 || col[j]==1 || p_d[i+j]==1 || s_d[n-i+j]==1) return false;
            return true;
        }
    
        void rec(int i, int n, vector<int>& row, vector<int>& col, vector<int>& p_d, vector<int>& s_d, vector<vector<string>>& ans, vector<string>& temp){
            if(i == n) {
                ans.push_back(temp);
                return;
            }
    
            for(int j=0;j<n;j++){
                if(isvalid(n,i,j,row,col,p_d,s_d)){
                    temp[i][j]='Q'; row[i]=1; col[j]=1; s_d[n-i+j]=1; p_d[i+j]=1;
                    rec(i+1,n,row,col,p_d,s_d,ans, temp);
                    temp[i][j]='.'; row[i]=-1; col[j]=-1; s_d[n-i+j]=-1; p_d[i+j]=-1;
                }
            }
            return;
        }
    
        vector<vector<string>> solveNQueens(int n) {
            vector<int> row(n+1,-1);
            vector<int> col(n+1,-1);
            vector<int> p_d(2*n,-1);
            vector<int> s_d(2*n,-1);
    
            vector<vector<string>> ans;
            vector<string> temp;
    
            for(int i=0;i<n;i++){
                string str = "";
                for(int j=0;j<n;j++){
                    str.push_back('.');
                }
                temp.push_back(str);
            }
    
            rec(0,n,row,col,p_d,s_d,ans,temp);
            return ans;
        }
    };