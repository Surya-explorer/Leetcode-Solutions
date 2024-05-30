class Solution {
public:
    int countPrimes(int n) {
        long long cnt = 0 ;
        if (n <= 2) return 0;
        std::vector<int> prime(n, 0);
        for (long long i = 2 ; i< n ; i++){
            if (prime[i] == 0 ){
                for (long long j = i*i ; j< n ; j+=i ){
                    prime[j] = 1 ;
                }
            }
        }
        for (long long i = 2 ; i< n ; i++ ){
            if (prime[i] == 0 ){
                cnt++ ;
            }
        }
        return cnt ;
    }
};




