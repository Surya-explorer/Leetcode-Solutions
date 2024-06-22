class Solution {
public:
    bool isValid(string s) {
        int open = 0 ;
        int close = 0 ;

        stack<char> st ;
        for (int i = 0 ; i< s.size() ; i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[' ) {
                st.push(s[i]) ; 
                open++ ;
            }
            else {
                if (st.empty()) return false  ; 
                char ch = st.top() ;
                st.pop() ;
                open-- ;

                if (ch == '(' && s[i] == ')' || ch == '{' && s[i] == '}' || 
                ch == '[' && s[i] == ']' )   continue ;
                else return false ;
            }
        }
        if (open > 0 ) return false ;
        return true ;
    }
};