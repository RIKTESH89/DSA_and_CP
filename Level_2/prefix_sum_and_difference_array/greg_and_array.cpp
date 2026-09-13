#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
    int n,m,k;cin>>n>>m>>k;
    vector<long long> nums(n);
    vector<vector<long long>> o;
    vector<long long> diff(m,0);
    vector<long long> diff2(n,0);
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<m;i++){
        long long x,y,z; cin>>x>>y>>z;
        o.push_back({x,y,z});
    }
    for(int i=0;i<k;i++){
        long long x,y; cin>>x>>y;
        diff[x-1]+=1;
        if(y<m) diff[y]-=1;
    }
    for(int i=1;i<m;i++) diff[i]+=diff[i-1];
    
    for(int i=0;i<m;i++){
        long long d = o[i][2], l = o[i][0], r = o[i][1];
        diff2[l-1]+=diff[i]*d;
        if(r<n) diff2[r]-=diff[i]*d;
    }
    for(int i=1;i<n;i++) diff2[i]+=diff2[i-1];
    for(int i=0;i<n;i++) {
        cout<<nums[i]+diff2[i]<<" ";
    }
    return 0;
    
}