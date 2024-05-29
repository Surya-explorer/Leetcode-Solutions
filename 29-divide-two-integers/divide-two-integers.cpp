class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (divisor == 0 ) return INT_MAX ;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long ans = 0  ;
        long long n = abs((long long)dividend)   ;
        long long d = abs((long long)divisor) ;

        bool sign = true ;
        if (dividend >0 && divisor < 0 ) sign = false ;
        if (dividend <0 && divisor > 0 ) sign = false  ;

        while (n >= d) {
            // long cnt = 0 ;
            // while (n >= d*(1 << (cnt+1)) && (cnt + 1) < 32) cnt ++ ;

            // ans = ans + (1<<cnt) ; 
            // n = n - d* (1<< cnt) ;

            long long temp = d, cnt = 1;
            while (n >= (temp << 1) && temp <= (LLONG_MAX >> 1)) {
                temp <<= 1;
                cnt <<= 1;
            }
            n -= temp;
            ans += cnt;
        }

        // if ((ans > ( 1 << 31)) && sign ) return INT_MAX ;
        // if ((ans > ( 1 << 31)) && !sign ) return INT_MIN ;    

 
        if (ans > INT_MAX && sign ) return INT_MAX ;
        if (ans > INT_MAX && !sign ) return INT_MIN ;

        return sign ? ans : -1 * ans ;
    }
};