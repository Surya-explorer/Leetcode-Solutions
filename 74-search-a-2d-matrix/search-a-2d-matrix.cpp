class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 1 && n == 1) if (matrix[0][0] == target) return true ;
        
        for (int i =  0 ; i <m ; i++ ){
            int s= 0 ;
            int e = n-1 ;
            int m  ;
            while (s <= e){
                m =  s+ (e-s)/2 ;
                if (matrix[i][m] == target  ){
                    return true ;
                }
                else if (matrix[i][m] < target){
                    s = m + 1 ;
                }
                else{
                    e = m - 1 ;
                }
            }
        }
        return false ;
    }
};