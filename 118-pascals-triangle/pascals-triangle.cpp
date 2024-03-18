class Solution {
public:
    int ncr( int n , int r ){
        long long res  = 1;
        for (int i = 0 ; i< r ; i++ ){
            res = res* (n-i) ;
            res = res/(i+1) ;
        }
        return (int)(res);
    }
    vector<vector<int>> generate(int numRows) {
        vector <vector<int>> ans ;
        for (int r = 1 ; r<= numRows ; r++ ){
            vector <int> temp ;
            for (int c = 1 ; c<= r ; c++ ){
                temp.push_back(ncr(r-1 , c-1 )) ;
            }
            ans.push_back(temp) ;
        }
        return ans ;
    }
};