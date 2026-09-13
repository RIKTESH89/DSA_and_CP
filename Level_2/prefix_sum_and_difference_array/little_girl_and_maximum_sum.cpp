#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
    int n,q; cin>>n>>q;
    multiset<int, greater<int>> nums;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        nums.insert(x);
    }
    multiset<int, greater<int>> f;
    vector<int> val(n,0);
    for(int i=0;i<q;i++){
        int x,y; cin>>x>>y;
        val[x-1]+=1;
        if(y<n) val[y]-=1;
    }
    for(int i=1;i<n;i++) val[i]+=val[i-1];
    for(int i=0;i<n;i++) f.insert(val[i]);
    auto it1 = nums.begin();
    auto it2 = f.begin();
    long long ans = 0;
    while(it1 != nums.end() && it2 != f.end()){
        ans += 1LL * (*it1) * (*it2);
        ++it1;
        ++it2;
    }
    cout<<ans;
    return 0;
}