class Solution {
    public:
    
        int rec(int n, int k){
            if(n==0) return 0;
            if(n==1){
                if(k==1) return 0;
                else if(k==2) return 1;
            }
    
            double pow_v = pow(2,n-1);
            int val = (int)pow_v;
    
            if(k<= val) return rec(n-1,k);
            else return 1 - rec(n-1,k-val);
    
        }
    
        int kthGrammar(int n, int k) {
            return rec(n-1,k);
        }
    };