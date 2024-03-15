class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        int maxPro = 0 ;
        int Minprice = INT_MAX ;
        for ( int i = 0 ; i< n ; i++ ){
            if (prices[i] < Minprice){
                Minprice = prices[i]  ;
            }
            maxPro = max(prices[i] - Minprice , maxPro )  ;
        }
        return maxPro ;
    }
};