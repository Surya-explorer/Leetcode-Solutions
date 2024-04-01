class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() ;
        int s = 1 ;
        int e  = n - 2 ;
        int mid ;
        if (n == 1) return 0  ;
        if(nums[0] > nums[1]) return 0 ;
        if (nums[n-1] > nums[n-2]) return n-1 ;
        while (s <= e){
            mid = (s + e)/2 ;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+ 1]){
                return mid ;
            }
            if ( nums[mid-1] < nums[mid] ){
                s = mid +1 ;
            } 
            else {
                e = mid -1 ;
            }
        }
        return -1 ;
    }
};