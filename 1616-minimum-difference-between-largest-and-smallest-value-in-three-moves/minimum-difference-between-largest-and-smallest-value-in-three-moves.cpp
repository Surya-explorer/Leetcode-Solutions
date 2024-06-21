class Solution {
public:
    int minDifference(vector<int>& nums) {
        int ans = 0 ;
        int n = nums.size() ;
        if (n <=4) return 0 ;

        sort(nums.begin() ,nums.end()) ;
        int result = INT_MAX;

        // Compare the difference between the maximum and minimum
        // after removing up to 3 smallest or largest elements
        for (int i = 0; i <= 3; i++) {
            result =min(result, nums[n - 4 + i] - nums[i]);
        }
        return result;
    }
};