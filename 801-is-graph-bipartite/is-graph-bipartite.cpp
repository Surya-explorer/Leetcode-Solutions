class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector <int> vis = {-1} ;
        queue <int> q ;
        
        // vector<int> colour = {-1 } ;
        vector<int> colour(n) ;
        for (int i = 0 ; i < n ; i++) colour[i] = -1 ;
        colour[0] = 0 ;
    
        // colour is a Parent colour 
        for (int k = 0 ; k < n ; k++ ){
            q.push(k) ;
            while (!q.empty()){
                int node = q.front()  ;
                q.pop() ;
                for(auto i : graph[node]){
                    // node is a parent of the node i ;
                    if (colour[i] == -1) {
                        colour[i] = !colour[node] ;
                        q.push(i) ;    
                    }
                    else if (colour[i] == colour[node] ) return false ;
                }
            }
        }
        
        return true ;
    }
};