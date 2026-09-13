#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
    int n,m,c;cin>>n>>m>>c;
    vector<long long> a(n);
    vector<long long> ans(n,0);
    vector<long long> b(m);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<int> pref(m,0); pref[0]=b[0];
    for(int i=1;i<m;i++) pref[i]+=pref[i-1] + b[i];
    for(int i=0;i<n;i++){
        int l = max(0,i-(n-m));
        int r = min(i,m-1);
        if(l<=0) ans[i] = (a[i]+pref[r])%c;
        else ans[i]= (pref[r]-pref[l-1]+a[i])%c;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
    
}