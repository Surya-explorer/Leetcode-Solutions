class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() , check = 0 ;
        int index = 0 ;
        for ( int i = 0 ; i< n ; i++ ){
            if (nums[i] == target ){
                check = 1 ;
                index = i ;
            }
        }
        if (check == 0 ){
            return -1 ;
        }
        return index ;
    }
};