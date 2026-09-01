#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    vector<vector<int>> diff(n,vector<int>(m,0));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++) {
            v[i][j] = s[j] - '0';
        }
    }

    int q;cin>>q;
    vector<vector<int>> query(q,vector<int>(4));
    for(int i=0;i<q;i++){
        for(int j=0;j<4;j++){
            cin>>query[i][j];
        }
    }
    
    for(int i=0;i<q;i++){
        int x1 = query[i][0]-1;
        int y1 = query[i][1]-1;
        int x2 = query[i][2]-1;
        int y2 = query[i][3]-1;
        
        diff[x1][y1] = 1^diff[x1][y1];
        
        if(x2+1<=n-1){
            diff[x2+1][y1] = 1^diff[x2+1][y1];
        }
        if(y2+1<=m-1){
            diff[x1][y2+1] = 1^diff[x1][y2+1];
        }
        if(x2+1<=n-1 && y2+1<=m-1){
            diff[x2+1][y2+1] = 1^diff[x2+1][y2+1];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i-1>=0) diff[i][j] = diff[i][j]^diff[i-1][j];
            if(j-1>=0) diff[i][j] = diff[i][j]^diff[i][j-1];
            if(i-1>=0 && j-1>=0) diff[i][j] = diff[i][j]^diff[i-1][j-1];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<(v[i][j] ^ diff[i][j]);
        }
        cout<<endl;
    }
    
    return 0;
    
}
