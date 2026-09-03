#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> o(n);
        vector<int> p(n,0);
        for(int i=0;i<n;i++) cin>>o[i];
        int m;cin>>m;
        int u_sum=0;
        for(int i=0;i<m;i++){
            int u;cin>>u;
            int l = u_sum;
            int r = u+u_sum;
            p[l]+=1;
            if(r<=n-1) p[r]-=1;
            else {
                p[0]+=1;
                p[(r%n)]-=1;
            }
            u_sum+=u;
            u_sum%=n;
            // cout<<"val of l "<<l<<" val of r "<<r<<endl;
        }
        for(int i=1;i<n;i++) p[i]+=p[i-1];
        
        int s_i=0; int val=p[0];
        for(int i=1;i<n;i++){
            if(p[i]<p[i-1]){
                val = p[i];
                s_i = i;
            }
        }
        cout<<o[s_i]<<endl;
        
    }
    return 0;
}
