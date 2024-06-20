class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0 ;
        int e = n -1 ;
        int mid = s + (e - s) / 2;
        while (s <= e ){
            mid = s + (e - s) / 2;
            if (nums[mid] == target) return mid  ;
            
            // Check for left sorted array .
            if (nums[s] <= nums[mid]) {
                if ( nums[s] <= target && target < nums[mid]) e = mid -1 ;
                else  s  = mid + 1 ;
            }
            // Check for right sorted array .
            else {
                if (nums[mid] < target && target <= nums[e]) s = mid + 1 ;
                else  e = mid - 1 ;
            }
            
        }
        return -1 ;
    }
};


// for ( int i = 0 ; i< n ; i++ ){
        //     if (nums[i] == target ){
        //         check = 1 ;
        //         index = i ;
        //     }
        // }
        // if (check == 0 ){
        //     return -1 ;
        // }