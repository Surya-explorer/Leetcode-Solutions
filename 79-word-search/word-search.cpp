class Solution {
public:
    // void solve (vector<vector<char>> board, string word , bool &ans , int r , int c  ,int index){
       
    //     if (index == word.length() ){
    //         ans = true ;
    //     }
    //     if (r< 0 || r == board.size() || c <0 || c== board[0].size() || board[r][c] != word[index] || board[r][c] == '#'){
    //         return ;
    //     }
    //     char ch = board[r][c] ;
    //     board[r][c] = '#' ;   // Marked as visited

    //     solve(board , word , ans , r+1 , c , index + 1 ) ; // Down
    //     solve(board , word , ans , r-1 , c , index + 1 ) ; // Up
    //     solve(board , word , ans , r , c+1 , index + 1 ) ; // Right
    //     solve(board , word , ans , r , c-1 , index + 1 ) ; // Left

    //     board[r][c] = ch ;  // Undo
    // }
    // bool exist(vector<vector<char>>& board, string word) {
    //     bool ans = false  ;
        
    //     for (int i = 0 ; i< board.size() ; i++ ){
    //         for (int j = 0 ; j< board[0].size() ; j++ ){
    //             if (board[i][j] == word[0]){
    //                 solve (board , word , ans , i , j, 0 ) ;
    //                 if (ans) return true;
    //             }
    //         }
    //     }
    //     return ans ; 
    // }
    bool searchNext(vector<vector<char>> &board, string word, int row, int col, 
    int index, int m, int n) {

        // if index reaches at the end that means we have found the word
        if (index == word.length())
            return true;

        // Checking the boundaries if the character at which we are placed is not 
        //the required character
        if (row < 0 || col < 0 || row == m || col == n || board[row][col] != 
        word[index] or board[row][col] == '!')
            return false;

        // this is to prevent reusing of the same character
        char c = board[row][col];
        board[row][col] = '!';

        // top direction
        bool top = searchNext(board, word, row - 1, col, index + 1, m, n);
        // right direction
        bool right = searchNext(board, word, row, col + 1, index + 1, m, n);
        // bottom direction
        bool bottom = searchNext(board, word, row + 1, col, index + 1, m, n);
        // left direction
        bool left = searchNext(board, word, row, col - 1, index + 1, m, n);

        board[row][col] = c; // undo change

        return top || right || bottom || left;
    }
    bool exist(vector<vector<char>> board, string word) {
        int m = board.size();
        int n = board[0].size();

        int index = 0;

        // First search the first character
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[index]) {
                    if (searchNext(board, word, i, j, index, m, n))
                        return true;
                }
            }
        }

        return false;
    }

};