class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        int m = 0;
        vector<int> ans(2 , -1);
        // if (nums.size() == 0 || nums.size() == 1) return {-1 , -1}  ;
        while (s <= e) {
            m = s + (e - s) / 2;
            if (nums[m] == target) {
                ans[0] = m;
                e = m - 1;
            } else if (nums[m] < target) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        s = 0;
        e = nums.size() - 1;

        while (s <= e) {
            m = s + (e - s) / 2;
            if (nums[m] == target) {
                ans[1] = m;
                s = m + 1;
            } else if (nums[m] < target) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        if (ans.empty())
            return {-1, -1};
        return ans;
    }
};