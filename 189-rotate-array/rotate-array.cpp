class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size() ;
        vector<int> a1(nums) ;
        if (size == 1 || size == 0 ){
            return ;
        }
        for (int i = 0 ; i  < size ; i++ ) {
            a1[(i+k)%size] = nums[i] ;
        }
        nums = a1 ;
    }
};  