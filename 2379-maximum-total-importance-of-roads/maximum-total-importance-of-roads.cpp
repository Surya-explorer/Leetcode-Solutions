class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector <long long > degree(n , 0 ) ;

        // Calculation of the indegree .
        for (int i = 0; i < roads.size() ; i++){
            int u = roads[i][0] ;
            int v = roads[i][1] ;
            degree[u] ++ ;  
            degree[v] ++ ;  
        }
        sort(degree.begin() , degree.end()) ;
        long long maxsum = 0 ;
        for (long long i = 1 ; i <= n ; i++){
            maxsum += i * degree[i-1] ;
        }

        return maxsum ;
    }
};