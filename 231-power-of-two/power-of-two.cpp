class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int cnt = 0 ;
        if (n < 0) return false ;
        while (n != 0 ){
            n = n & (n-1) ;
            cnt ++ ;
            
            // if (n%2 == 1) cnt++   ;
            // n = n / 2 ;
        }
        if (cnt == 1) return true  ;
        else    return false ;     
        
        }
};