class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum =0 ;
        int maxsum = INT_MIN ;
        int cnt = 0 ;
        // int maxi =  ;
        // if nums contains only negative numbers .
        // for (int i = 0 ; i < nums.size()  ; i++){
        //     if (nums[i] < 0 ) cnt++ ;
        //     maxi = max (maxi , nums[i]) ;
        // }

        // if (cnt == nums.size()) return maxi ;

        // if nums contains mix of negative and postive numbers .
        for (int i = 0 ; i < nums.size() ; i++){
            
            sum+= nums[i] ;
            maxsum = max (maxsum , sum ) ;
            if (sum < 0 ) sum= 0 ;

        }
        return maxsum ;


    }
};