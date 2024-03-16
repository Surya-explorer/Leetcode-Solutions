class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size() ;  // Row 
        int n = matrix[0].size() ; // Col
        // Row --> matrix[0][]
        // col --> matrix[][0]
        int col1 = 1 ;
        for (int i = 0 ; i< m ; i++ ){
            for (int j = 0 ; j< n ; j++ ){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0 ;
                    if (j!= 0)
                        matrix[0][j] = 0;
                    else 
                        col1 = 0 ;
                }
            }
        }
        for (int i = 1 ; i< m ; i++  ){
            for (int j = 1 ; j< n ; j++){
                if (matrix[i][j] != 0){
                    // Check for the col and row 
                    if (matrix[0][j] == 0 ||  matrix[i][0] == 0){
                        matrix[i][j] = 0 ;
                    }
                }
            }
        }
        if (matrix[0][0] == 0){
            for (int j = 0 ; j < n ;j++ ){
                matrix[0][j] = 0 ;
            }
        }
        if (col1 == 0){
            for (int i = 0 ; i < m ;i++ ){
                matrix[i][0] = 0 ;
            }
        }
        return ;
    }
};