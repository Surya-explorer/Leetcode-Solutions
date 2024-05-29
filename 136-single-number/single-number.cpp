class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int count = 0 ;
        // int n = nums.size() ;
        // if ( n==1 ){
        //     return nums[n - 1] ;
        // }
        // sort (nums.begin() , nums.end() ) ;
        // for (int i = 0 ; i< n - 1 ; i+=2  ){
        //     if (nums[i] != nums[i+1]){
        //         count = i ;    
        //         return nums[count] ; 

        //     } 
        // }  
        // return nums[n - 1] ;
        

        int ans = 0 ;

        for (auto num : nums ){
            ans = ans^ num  ;

        }
        return ans ;

    }
};