class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int maxlen = 0 ;
        string ans = "" ;
        
        for (int i = 0 ; i < s.size() ;i++){
            // Checking for the odd palindromic string 
            int prev = i ;
            int next = i ;
            while (prev >=0 && next <= s.size()-1 && s[prev] == s[next] ){
                prev -- ;
                next ++ ;
            }
            int len = next - prev  -1;
            if (maxlen  < len  ){
                maxlen = len ;
                ans = s.substr(prev +1, len) ;
            }
            // check for even palindromic string
            
            prev = i ;
            next = i+1 ;
            while (prev >=0 && next <= s.size()-1 && s[prev] == s[next] ){
                prev -- ;
                next ++ ;
            }
            len = next - prev -1;
            if (maxlen  < len  ){
                maxlen = len ;
                ans = s.substr(prev +1 , len) ;
            }
        } 
        return ans ;
    }
};