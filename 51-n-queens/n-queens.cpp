class Solution {
public:
    bool isSafe (int r ,int c , vector<string> &Matrix , int n ){
        int dupr = r ;
        int dupc = c ;

        while (r>= 0 && c>=0){
            if (Matrix[r][c] == 'Q'){
                return false ;
            }
            r-- ;
            c--  ;
        }

        r= dupr ;
        c= dupc ;

        while( c>= 0 ){
            if (Matrix[r][c] == 'Q'){
                return false ;
            }
            c-- ;
        }

        r= dupr ;
        c= dupc ;

        while (r<n && c>=0){
            if (Matrix[r][c] == 'Q'){
                return false ;
            }
            r++ ;
            c-- ;
        }
        return true ;
    }
    public:
    void solve (int c , int n , vector <vector <string>> &ans , vector <string>& Matrix ) {
        if ( c == n ){
            ans.push_back(Matrix)  ;
            return ;
        }
        for (int r = 0 ; r<n ; r++ ){
            if (isSafe (r ,c , Matrix , n )){
                Matrix[r][c] = 'Q' ;
                solve(c+1 ,  n , ans , Matrix) ;
                Matrix[r][c] = '.' ;
            }
        }
    }
    public:

    vector<vector<string>> solveNQueens(int n) {
        vector <vector <string>> ans ;
        vector <string> Matrix(n) ;
        string s(n , '.') ;

        for (int i = 0 ; i< n ; i++ ){
            Matrix[i] = s ;
        }
        solve(0,  n , ans , Matrix) ;
        return ans ;
    }
};