class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int check = 0 ,  n = nums.size() ;
        int s = 0 ;
        int e = n -1 ;
        int mid = s + (e-s)/2 ;
        while ( s <= e){
            mid = s + (e-s)/2 ;
            if (nums[mid] == target ){
               return true ;
            }
            // Edge Case 
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++ ;
                e-- ;
                continue;
            }
            // if left part is sorted 
            if ( nums[s] <= nums[mid] ){
                if (nums[s]<= target && target <= nums[mid]){
                    e = mid -1 ;
                }
                else{
                    s =  mid + 1 ;
                }
            }
            // if the right part is sorted 
            else if ( nums[mid] <= nums[e] ){
                if (  nums[mid] <= target && target <= nums[e]){
                   s =  mid + 1 ;
                }
                else{
                   e = mid -1 ;
                }
            }
        }
        return false ;
    }
};