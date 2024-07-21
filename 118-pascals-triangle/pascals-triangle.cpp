class Solution {
public:

    int ncr(int r , int c){
        long long res = 1 ;

        for (int r1 = 0 ; r1 <=c-1 ; r1++){
            res = res * (r-r1) ;
            res /= r1+1 ;
        }
        return  (int)(res) ;
    }
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> ans ;
        for (int r = 1 ; r <= numRows ; r++){
            vector<int> temp ;
            for (int c = 1 ; c <= r ; c++ ){
                temp.push_back(ncr(r-1 , c-1 )) ;
            }
            ans.push_back(temp) ;
        }
        return ans ;
    }
};