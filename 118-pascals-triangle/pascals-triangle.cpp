class Solution {
public:

    int ncr (int n , int r){
        int prod = 1 ;
        for (int i = 0 ; i < r ; i++){
            prod = prod * (n-i) ;
            prod /= (i+1) ;
        }
        return prod ;
    } 
    vector<vector<int>> generate(int numRows) {
        vector <vector <int> > ans ;
        int n = numRows ;
        for (int n = 0 ; n < numRows ; n++){
            vector <int>  a ;
            for(int r = 0 ; r <= n ; r++){
                a.push_back( ncr(n, r)) ;
            }
            ans.push_back(a) ;
        }
        return ans ;
    }
};