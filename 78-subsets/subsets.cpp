class Solution {
public:
    void solve (vector<int>nums , vector< vector<int> > &ans , vector<int>part , int index )  {
        if (index == nums.size()) {
            ans.push_back(part) ;
            return ;
        }
        // Excluding nums[index]
        solve(nums , ans , part , index + 1) ;

        // Including nums[i]
        int element = nums[index] ;
        part.push_back(element) ;
        solve(nums , ans , part , index + 1) ;
        // part.pop_back() ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int>> ans ;
        vector <int> part;
        solve (nums , ans , part  , 0) ;
        return ans ;
    }
};