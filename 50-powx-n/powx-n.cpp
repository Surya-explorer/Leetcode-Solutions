class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0 ;
        long long nn = n  ; // This is done to avoid stack overflow ;
        if (nn < 0 ) nn = nn * -1 ;
        while (nn)  {
            if (nn %2  == 1){
                ans = ans * x ;
                nn-- ;
            }
            else {
                x = x*x ;      // (x)^n =  ((x)^2)^n/2 
                nn = nn / 2 ;   //   (x)^n  =  x*((x)^2)^(n-1)/2
            }
        }
        if (n < 0) return 1/ans ;
        return ans ;
    }
};