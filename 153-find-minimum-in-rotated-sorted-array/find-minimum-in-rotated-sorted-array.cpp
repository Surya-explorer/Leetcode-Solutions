class Solution {
public:
    int findMin(vector<int>& nums) {
        int s= 0 ;
        int e = nums.size() -1  ;
        int mid ;
        int ans = INT_MAX ;
        while (s <= e ){
            mid = s+ (e-s)/2 ;
            if (nums[s] <= nums[e]) {
                ans = min(ans, nums[s]);
                break;
            }
            //if left part is sorted:
            if (nums[s] <= nums[mid]){ 
                ans = min (ans, nums[s] ) ;  
                s = mid + 1 ; // Inorder to approach to minimum
            }
            //if right part is sorted:
            else {
                ans = min (ans, nums[mid] ) ;    
                e = mid - 1 ;  // Inorder to approach to minimum
            }
        }
        return ans ;
    }
};