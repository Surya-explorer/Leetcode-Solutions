class Solution {
public:



    void solve(vector<int>& nums , vector <vector <int>> &ans , int index , vector <int> output ) {
        if (index == nums.size()){
            ans.push_back(output) ;
            return ;
        }
        output.push_back(nums[index]) ;
        solve(nums , ans , index+ 1 , output) ;

        output.pop_back() ;
        solve(nums , ans , index+ 1 , output) ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int>> ans ;
        vector <int> output= {} ;
        solve(nums , ans , 0 ,output );

        return ans ;
    }
};