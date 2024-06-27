class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // map<int , int> mp ;
        // vector <int > v ;
        // for (int i = 0 ; i < edges.size() ; i++ ){
        //     v = edges[i] ;
        //     int a= v[0] ;
        //     int b= v[1] ;
        //     mp[a]++ ;
        //     mp[b]++ ;
        // }
        // int maxnum = INT_MIN ;
        // v.push_back(0) ;
        // map<int , int > :: iterator it = mp.begin();
        // for ( it  ; it!= mp.end() ; it++){
        //     int ele = it ->first  ;
        //     int cnt  = it ->second ;
        //     if (cnt > maxnum ){
        //         maxnum = cnt ;
        //         v.pop_back() ;
        //         v.pop_back() ;
        //         v.push_back(ele) ;
        //         v.push_back(cnt) ;
        //     }
        // }
        // return v[0] ;
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        } 
        else {
            return edges[0][1];
        }
    }
};