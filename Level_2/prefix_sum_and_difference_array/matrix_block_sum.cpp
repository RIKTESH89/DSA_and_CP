class Solution {
    public:
        vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
            int n = mat.size();
            int m = mat[0].size();
            vector<vector<int>> prefix(n,vector<int>(m,0));
    
            for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[i].size();j++){
                    int left, diag, up;
                    if(i-1<0) left = 0;
                    else left = prefix[i-1][j];
                    if(j-1<0) up = 0;
                    else up = prefix[i][j-1];
                    if(i-1<0 || j-1<0) diag = 0;
                    else diag = prefix[i-1][j-1];
    
                    prefix[i][j] = mat[i][j] + left + up - diag;
                }
            }
    
            vector<vector<int>> ans(n,vector<int>(m,0));
            for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[i].size();j++){
                    int full, left_p, top_p, diag_p;
                    
                    full = prefix[min(n-1,i+k)][min(m-1,j+k)];
                    if(j-k-1<0) left_p = 0;
                    else left_p = prefix[min(n-1,i+k)][j-k-1];
                    if(i-k-1<0) top_p = 0;
                    else top_p = prefix[i-k-1][min(m-1,j+k)];
                    if(i-k-1<0 || j-k-1<0) diag_p = 0;
                    else diag_p = prefix[i-k-1][j-k-1];
    
                    ans[i][j] = full - left_p - top_p + diag_p;
                }
            }
            return ans;
        }
    };