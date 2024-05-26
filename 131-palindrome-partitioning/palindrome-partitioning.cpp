class Solution {
public:
    bool isPalindrome (string s , int i , int j ){
        while(i<=j){
            if (s[i] != s[j]){
                return false ;
            }
            i++ ;
            j-- ;
        }
        return true ;
    }
    void solve (string s , vector<vector<string>> &ans , vector<string> a , int i){
        
        if (i == s.length()) {
            ans.push_back(a) ;
        }
        for (int j = i ; j<s.length() ; j++ ){
            if (isPalindrome(s , i , j)){
                a.push_back(s.substr(i , j - i + 1 )) ;
                solve(s , ans , a , j+1) ;
                a.pop_back() ;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector <vector<string>> ans ;
        vector <string> a ;
        solve (s , ans , a , 0) ;

        return ans ;
    }
};