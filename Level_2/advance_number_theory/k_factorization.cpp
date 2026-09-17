#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n,k; cin>>n>>k;
    if(k==1){
        cout<<n;
        return 0;
    }
    vector<int> spf(n+1,-1);
    for(int i=2;i<n+1;i++){
        if(spf[i]==-1){
            for(int j=i;j<n+1;j+=i) if(spf[j]==-1) spf[j]=i;
        }
    }
    int count = 0, num = n;
    vector<int> ans;
    while(num>1){
        ans.push_back(spf[num]);
        num=num/spf[num];
        if(ans.size()==k-1) {
            if(num>1)
            ans.push_back(num);
            break;
        }
    }
    if(ans.size()<k) cout<<"-1";
    else
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}
