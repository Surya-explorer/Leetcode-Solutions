class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        // Answer is the number of the set bits in the xor of the two numbers .
        
        // int xor1 = (start ^ goal) ;
        // int cnt = 0 ;
        // for (int i = 1 ; i<=31 ; i++){

        //     if (xor1 & (1<< i)){
        //         cnt ++ ;
        //     }
        // }
        // return cnt ;


        int xor1 = (start)^(goal) ;
        int cnt = 0 ;

        while (xor1 != 0 ){
            xor1 = xor1 & (xor1-1) ;

            cnt ++ ;
        }
        return cnt ;
    }
};