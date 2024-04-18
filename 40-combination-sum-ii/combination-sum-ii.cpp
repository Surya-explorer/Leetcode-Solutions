class Solution {
public:
    // void solve (vector <vector <int>> &ans , int target , vector<int>& candidates, vector <int> temp , int i){
    //     // base case : -
    //     if (target == 0){
    //         ans.push_back(temp) ;
    //     }
    //     int j = i ;
    //     // while(target-candidates[j] >= 0 ){
    //     for (int j = i; j < candidates.size(); i++) {
    //         if ( j> i && candidates[i] == candidates[i- 1]) continue;
    //         if (candidates[j] > target) break;
    //         temp.push_back(candidates[j]) ;
    //         solve(ans , target-candidates[j] ,candidates , temp , j) ;
    //         j++ ;
    //         temp.pop_back() ;
    //     }
    // }
    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
    //     sort(candidates.begin() , candidates.end()) ;
    //     vector <vector <int>> ans ;
    //     vector <int> temp ;
    //     candidates.erase(unique(candidates.begin() , candidates.end()) , candidates.end() ) ;
    //     solve (ans , target , candidates , temp , 0) ;
    //     return ans ;
    // }
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
        if (target == 0) {
          ans.push_back(ds);
          return;
        }
        for (int i = ind; i < arr.size(); i++) {
          if (i > ind && arr[i] == arr[i - 1]) continue;
          if (arr[i] > target) break;
          ds.push_back(arr[i]);
          findCombination(i + 1, target - arr[i], arr, ans, ds);
          ds.pop_back();
        }
    }
    vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector < vector < int >> ans;
        vector < int > ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
