class Solution {
public:

    void solve (vector <vector <int>> &ans , int target , vector <int> candidates ,int index , vector <int> temp){
        // Base case : -
        int n = candidates.size() ;
        if (target == 0 && index < n){
            ans.push_back(temp) ;
        }
        while (index < n && target-candidates[index] >= 0){
            // sum += candidates[index] ;
            temp.push_back(candidates[index]) ;
            solve(ans , target - candidates[index] , candidates ,index , temp) ;
            index++ ;
            temp.pop_back() ;

        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector <int>> ans  ;
        sort(candidates.begin(), candidates.end());
        // remove duplicates
        // candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        int index = 0 ;
        vector <int> temp ;
        int n = candidates.size() ;
        solve (ans , target , candidates, index , temp) ;

        return ans ;
    }
};