class Solution {
public : 
    void solve ( vector <int> nums , vector <vector<int>> &ans , vector <int> a , int i  , int n){
        ans.push_back(a) ;
        for (int j = i ; j < n ; j++){
            if (j != i && nums[j] == nums[j-1] ) continue ;
            a.push_back(nums[j]) ;
            solve(nums, ans , a , j+1 , n) ;
            a.pop_back() ;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <vector<int>> ans ;
        vector <int> a ;
        int i = 0 ;
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        solve (nums , ans , a , i , n ) ;
        return ans ;
    }
};