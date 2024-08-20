class Solution {
public:
    string minWindow(string s, string t) {
        
        int minLen = INT_MAX ;
        int sindex = -1 ;

        unordered_map<int , int> hash ;
        
        int cnt = 0 ;
        int l = 0 ;
        int r = 0 ;  
        
        hash[256] = {0} ;
        for (int j = 0 ; j <t.size()  ; j++) hash[t[j]] ++ ;
        while( r < s.size()) {
            if (hash[s[r]] > 0) cnt = cnt + 1 ;
            hash[s[r]] -= 1 ;
            while (cnt == t.size() ){
                if ( r - l + 1 < minLen){
                    minLen = r - l + 1 ;
                    sindex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt = cnt -1 ;
                l++ ;
            }
            r++ ;
        }    
        return  sindex == -1 ? "" : s.substr(sindex , minLen) ; 
    }
};










// map< char , int > mp ;
//         for (int i = 0 ; i < t.size() ;i++){
//             mp[t[i]]++ ;
//         } 
//         int size = mp.size() ;
//         vector <int> index ={} ;
//         int large_size = 1000;  
//         string ans = string(large_size, 127);

//         for (int i = 0 ; i < s.size() ; i++){
//             auto it = mp.begin();
//             char j = it->first;  
//             it++ ;
//             if (size == 0 ){
//                 string s1 = s.substr( 0  ,   index.size() - 1 ) ;
//                 if (ans.size() > s1.size()){
//                     ans = s1 ;
//                 }
//                 size = mp.size() ;
//                 int n = index.size() ;
//                 while (n--){
//                     index.pop_back() ;
//                 }
//             }
//             if ( s[i] == j ) {
//                 size -= 1  ;
//                 index.push_back(i) ;
//             }
//         }
//         return ans ;