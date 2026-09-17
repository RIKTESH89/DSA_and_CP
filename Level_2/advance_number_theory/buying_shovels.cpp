#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k; int ans=1;
        if(k>=n){
            cout<<1<<endl;
            continue;
        }
        for(int i=1;i*i<=n;i++){
            if(n%i!=0) continue;
            if(i<=k){
                ans=max(ans,i);
            }
            if(n/i <= k) ans=max(ans,n/i);
            
        }
        cout<<n/ans<<endl;
    }
    return 0;
}
