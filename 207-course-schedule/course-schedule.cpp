class Solution {
public:
    // void dfs(vector<int> adj[]  , vector <int> &vis ,int node , stack<int> &st  ){

    //     vis[node] = 1 ;
    //     for (auto j : adj[node]){
    //         if (!vis[j]) dfs (adj , vis ,j , st  )  ;
    //     }
    //     st.push(node )   ;
    // }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses] ;
        for (auto it : prerequisites ) {
            adj[it[1]].push_back(it[0]) ;
        }

        // The following steps is for undirected graph , so therfore we use kahn 
        // method  (BFS method for topological sort )

        // vector <int> vis(numCourses , 0) ;
        // stack <int> st ;
        // for (int i = 0 ; i < numCourses ; i++){
        //     if (!vis[i]) dfs (adj , vis , i , st ) ;
        // }

        // if (st.size() == numCourses) return true ;

        // return false ;

         
	    vector <int> indegree ( numCourses , 0);
	    vector <int> topo;
	    queue <int > q ;
	   
	    for (int i= 0 ; i < numCourses ; i++) {
	        for (auto j : adj[i]){
	             indegree[j]++ ;   
	        }
	    }
	    for (int i = 0 ; i <numCourses ; i++) {
	        if (indegree[i] == 0 ) q.push(i) ;  
	    }
	    
	    while (!q.empty()){
            int node = q.front() ;
            q.pop() ;
            
            topo.push_back(node) ;
            for (auto j : adj[node]){
                indegree[j] -- ;
                
                if (indegree[j] == 0 )q.push(j) ;
            } 
        }
	    if (topo.size() == numCourses ) return true ;
        return false ;
    }
};