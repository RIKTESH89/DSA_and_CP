#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int rec(vector<vector<char>>& v, int i, int j, int n, vector<vector<int>>& dp){
    if(i>=n || j>=n || i<0 || j<0 ||v[i][j]=='*') return 0;
    if(i== n-1 && j==n-1){
        return 1;
    }
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    return dp[i][j] = (rec(v,i+1,j,n,dp)% MOD + rec(v,i,j+1,n,dp)% MOD)% MOD;
}

int main() {
	// your code goes here
    int n; cin>>n;
    vector<vector<char>> v(n, vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>v[i][j];
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    
    cout << rec(v, 0, 0, n, dp) << '\n';
    
    return 0;
}
