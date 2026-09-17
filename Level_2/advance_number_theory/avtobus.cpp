#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        if(n<4 || n%2 !=0) {
            cout<<"-1"<<endl;
        }
        else{
            long long x = (n+5)/6;
            long long y = n/4;
            cout<<x<<" "<<y<<endl;
        }
    }
    return 0;
}
