class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum =0 ;
        int maxsum = 0 ;
        int cnt = 0 ;
        int maxi = INT_MIN ;

        for (int i = 0 ; i < nums.size()  ; i++){
            if (nums[i] < 0 ) cnt++ ;
            maxi = max (maxi , nums[i]) ;
        }

        if (cnt == nums.size()) return maxi ;
        for (int i = 0 ; i < nums.size() ; i++){
            sum+= nums[i] ;

            if (sum < 0 ) sum= 0 ;

            maxsum = max (maxsum , sum ) ;
        }
        return maxsum ;


    }
};