class Solution {
public:

    void solve( vector <vector <int> > &ans , vector<int>& nums ,  int index   , vector<int> v ){

        if (index == nums.size()){
            ans.push_back(nums) ;
            return ;
        }
        for (int i = index ; i < nums.size() ; i++){

            swap (nums[index] , nums[i]) ;
            solve (ans , nums , index+ 1 , v) ;
            swap (nums[index] , nums[i]) ;
            // v.push_back(nums[i]) ;
            // solve (ans , nums , index , v ) ;
            // v.pop_back() ;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0 ;
        vector <vector <int> > ans ;
        vector <int> v = {} ;
        solve (ans , nums , index , v ) ;

        return ans ;
    }
};