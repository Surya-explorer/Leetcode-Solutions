class Solution {
public:
    // void solve (int n , int &cnt ){
    //     if (n == 0 ) {
    //         cnt += 1 ;
    //         return  ;
    //     }
    //     if ( n < 0) return ;
    //     solve (n-1 , cnt) ;
    //     solve (n-2 , cnt) ;
    // }
    int climbStairs(int n) {
        
        vector <int> dp(n+1 ) ;
        dp[0] =1 ;
        dp[1] =1 ;
        for (int i = 2 ; i <= n ; i++){

            dp[i] = dp[i-1] + dp[i-2] ;
        }
        return dp[n] ;

    }
};
