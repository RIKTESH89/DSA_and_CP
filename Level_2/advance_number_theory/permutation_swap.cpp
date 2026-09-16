#include <bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int>& v){
    for(int i=0;i<v.size()-mid;i++){
        if(v[i]!=i+1) swap(v[i],v[i+mid]);
    }
    for(int i=0;i<v.size();i++) if(v[i]!=i+1) return false;
    return true;
}

int main() {
	// your code goes here
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        int ans = 0;
        for(int i=0;i<n;i++){
            int x; cin>>x;
            ans = gcd(ans, abs(x-i-1));
        }
        cout<<ans<<endl;
    }
    return 0;
}
