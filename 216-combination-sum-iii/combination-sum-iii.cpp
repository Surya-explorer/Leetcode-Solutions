class Solution {
public:
    void solve (int k , int n , vector <vector <int>> &ans , vector <int> a , int i ){

        if ( a.size() == k && n == 0){
            ans.push_back(a)  ;
            return ;
        }
        for (int i = a.empty() ? 1 : a.back()+1 ; i <= 9 ; i++){
            if (n-i < 0 ) break ;
            a.push_back(i) ;
            solve (k, n-i , ans , a , i+1) ;
            a.pop_back() ;
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <vector <int>> ans ;
        vector <int> a ;
        solve (k , n , ans , a , 1 ) ;
        return ans ;
    }
};