#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
    int n,k,q; cin>>n>>k>>q;
    vector<int> v(200002,0);
    for(int i=0;i<n;i++){
        int x;int y; cin>>x>>y;
        v[x]+=1;
        if(v[y+1]<=200000) v[y+1]-=1; 
    }
    for(int i=1;i<v.size();i++){
        v[i]+=v[i-1];
    }
    vector<int> pre(200002,0);
    for(int i=1;i<v.size();i++){
        pre[i] = pre[i-1] + (v[i]>=k);
    }
    for(int i=0;i<q;i++){
        int a; int b; cin>>a>>b;
        int l = max(0,a-1);
        int r = b;
        cout<<pre[r]-pre[l]<<endl;
    }
    return 0;
}