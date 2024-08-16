class Solution {
public:

    void solve (string s , int opencnt , bool &ans , int index ){
        
        if (index == s.size()) return ;

        for (int i =  index ; i < s.size() ; i++){
            if (s[i] == '[' || s[i] == '(' || s[i] == '{' ) {
                opencnt ++ ;
                solve (s , opencnt , ans , index+1 );
            }
            if ( i > 0 ) {
                if ( s[index] ==  '[' &&  s[i] == ']' || s[index] ==  '(' &&  s[i] == ')' || s[index] ==  '{' &&  s[i] == '}'){
                    ans = true ;
                    continue ;
                }
                else {
                    ans = false  ;
                }
            }  
        }
    }
    bool isValid(string s) {
        int opencnt = 0 ;
        // bool ans  = true ;
        
        stack <char> st ;

        for (int i =  0 ; i < s.size() ; i++){
            if (s[i] == '[' || s[i] == '(' || s[i] == '{' ) {
                opencnt ++ ;
                st.push(s[i]) ;
                // solve (s , opencnt , ans , index+1 );
            }
            else {
                if (st.empty()) return false ;
                char ch = st.top() ;
                opencnt-- ;
                
                st.pop() ;
                
                if ( ch ==  '[' &&  s[i] == ']' || ch ==  '(' &&  s[i] == ')' 
                   || ch ==  '{' &&  s[i] == '}') {
                    continue ;
                }
                else {
                    return false ;
                }
            }
        }
        if (opencnt > 0  ) return false ;
        return true ;
    }
};