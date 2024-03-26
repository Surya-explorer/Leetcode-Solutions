class Solution {
public:

    int firstoccurence (vector <int> nums , int target , int n ){
        int s = 0, e = n - 1, mid;
        int first = -1;
        while (s <= e) {
            mid = (s + e) / 2;
            if (nums[mid] == target) {
                first = mid;
                e = mid - 1;
            }
            else if (nums[mid] > target) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return first ;
    }
    int lastoccurence (vector <int> nums , int target , int n ){
        int s = 0, e = n - 1, mid;
        int last = -1;
        while (s <= e) {
            mid = (s + e) / 2;
            if (nums[mid] == target) {
                last = mid;
                s = mid + 1 ;
            }
            else if (nums[mid] > target) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return last ;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size() ;
        int first = firstoccurence (nums , target , n) ;
        if (first == -1 ) return {-1 , -1 } ;
        int last = lastoccurence (nums , target , n) ;
        return {first , last} ;
    }
};