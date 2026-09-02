#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin>>t;
    while(t--){
        int n; int q; cin>>n>>q;
        
        vector<int> v(n,0);
        for(int i=0;i<q;i++){
            int l; int r; cin>>l>>r;
            
            v[l-1]+=1; if(r-1<n-1) v[r]-=(r-l+2);
            if(r<n-1) v[r+1] +=r-l+1;
        }
        
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
        }
        
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
        }
        
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}
