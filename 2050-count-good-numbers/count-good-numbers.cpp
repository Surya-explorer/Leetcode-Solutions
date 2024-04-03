class Solution {
public:
    int countGoodNumbers(long long n) {
        int MOD = 1000000007;
        long long ans = 1;

        ans = (ans * fastExpo(5, (n + 1) / 2, MOD)) % MOD; // Compute 5^(n+1)/2
        ans = (ans * fastExpo(4, n / 2, MOD)) % MOD;        // Compute 4^(n/2)

        return ans;
    }

private:
    long long fastExpo(long long base, long long exponent, int MOD) {
        long long result = 1;
        base %= MOD;

        while (exponent > 0) {
            if (exponent & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent >>= 1;
        }

        return result;
    }
};
