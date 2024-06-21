class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0 ;
        int curr = startFuel ;
        priority_queue <int , vector <int>> pq ;
        // sort (stations.begin() , stations.end()) ;
        
        for (int i = 0 ; i <= stations.size() ; i++) {
            if (curr >= target ) return 0 ;
            int nextStationDist = (i < stations.size()) ? stations[i][0] : target;
            // int nextStationDist = stations[i][0] ;
            while (curr < nextStationDist)  {
                if (pq.empty()) return -1 ;
                ans++ ;
                curr += pq.top() ;
                pq.pop() ;
            }
            if ( curr >= target) return ans ;
            if (i < stations.size()) pq.push(stations[i][1]) ;
        }
        return ans ;
    }
};