class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int>> ans ;
        
        int n = nums.size() ;
        for (int num = 0  ; num < (1<<n) ; num++ ){
            vector <int> part;
            for (int j = 0 ; j<=n-1  ; j++ ) {
                if (num & (1<<j) ){
                    part.push_back(nums[j]) ;
                }
            }
            ans.push_back(part) ;
        }
        return ans ;
    }
};