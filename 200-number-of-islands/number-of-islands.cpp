class Solution {

private : 
    void bfs(vector<vector<char>>& grid , vector<vector<int>>&vis ,
    int row , int col ){
        
        vis[row][col] = 1 ;
        int n = grid.size() ;
        int m = grid[0].size() ;
        queue <pair <int , int >> q ;
        q.push({row , col}) ;
        
        int deltas[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()){
            int row = q.front().first ;
            int col = q.front().second ;
            q.pop() ;

            for (int i = 0; i < 4; i++){
                int nrow = row + deltas[i][0];
                int ncol = col + deltas[i][1];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    
                    vis[nrow][ncol] = 1 ;
                    q.push({nrow , ncol}) ;
                }
            }
        }
        
        // while (!q.empty()){
        //     int row = q.front().first ;
        //     int col = q.front().second ;
        //     q.pop() ;

        //     for (int delrow = -1 ; delrow <= 1 ; delrow++){
        //         for (int delcol = -1 ; delcol <= 1 ; delcol++){
        //             int nrow = delrow + row ;
        //             int ncol = delcol + col ;
        //             if (grid[nrow][ncol] == '1' && !vis[nrow][ncol] 
        //             && nrow >= 0 && nrow < n && ncol >= 0 && ncol < m ){

        //                 vis[nrow][ncol] = 1 ;
        //                 q.push({nrow , ncol }) ;
        //             }
        //         }
        //     }
        // }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector <vector <int>> vis (n , vector <int>(m , 0) ) ;
        int cnt = 0 ;
        for (int row = 0 ; row < n ; row++ ){
            for (int col = 0 ; col < m ; col++  ){
                if (!vis[row][col] && grid[row][col] == '1'){
                    cnt ++ ;
                    bfs (grid , vis , row , col ) ;
                }
            }
        }
        return cnt ;
    }
};