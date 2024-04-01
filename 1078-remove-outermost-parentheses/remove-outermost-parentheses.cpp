class Solution {
public:
    string removeOuterParentheses(string s) {
        int opencount = 0 ;
        int closecount = 0 ;
        string result = "";
        int start = 0 ;

        for (int i = 0 ; i< s.length() ; i++){
            char c = s[i] ;
            if (c == '('){
                opencount ++ ;
            }
            else if (c == ')'){
                closecount ++ ;
            }
            if (opencount == closecount ){
                result += s.substr(start + 1 , i-1- start) ;
                start = i+ 1 ;
            }
        }
        return result ;
    }
};