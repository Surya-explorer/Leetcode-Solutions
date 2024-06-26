class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size() ;
        // if (n == 0 ){
        //     return "" ;
        // }
        // if ( n == 1){
        //     return strs[0] ;
        // }
        sort (strs.begin() , strs.end()) ;
        int Min = min (strs[0].size() , strs[n-1].size() ) ;
        string first = strs[0] , last = strs[n-1] ;
        int i = 0 ;
        while ( i< Min && first[i] == last[i] ) {
            i++ ;
        }
        string ans = first.substr(0 , i) ;
        return ans ;
    }
};