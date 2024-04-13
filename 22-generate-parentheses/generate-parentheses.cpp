class Solution {
public:
    void solve (int n , string s  ,vector <string> &ans  ,int open , int close){
        if (s.size() == 2*n ) {
            ans.push_back(s) ;
            return ;
        }
        if (open < n ) solve(n , s + "(", ans  , open + 1 , close) ;
        if (close < open  ) solve(n , s + ")", ans  , open , close + 1) ;
    }
    vector<string> generateParenthesis(int n) {
        // if (n == 0 ) return {""} ;
        vector <string> ans = {};
        int open = 0 , close = 0 ;
        solve (n , "" ,  ans , open , close  ) ;
        return ans ;
    }
};   