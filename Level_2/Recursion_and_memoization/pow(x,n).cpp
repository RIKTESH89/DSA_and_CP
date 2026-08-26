class Solution {
    public:
    
        double rec(double x, long long n){
            if(n==0) return 1;
            if(n==1) return x;
            if(n==2) return x*x;
            
                double val = rec(x,n/2);
            if(n%2 == 0){
                return  val * val;
            }
            else return x * val * val ;
        }
    
        double myPow(double x, int n) {
            long long N = n;
            if(n<0) return 1.0/rec(x,N);
            else return rec(x,N);
        }
    };