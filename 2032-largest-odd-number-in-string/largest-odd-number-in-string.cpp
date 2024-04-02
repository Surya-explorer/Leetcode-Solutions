class Solution {
public:
    string largestOddNumber(string num) {
        // int Max = INT_MIN ;
        // string s = "" ;
        // int n = num.length() ;
        // int integer = 0 ;
        // for (int i = 0 ; i< n ; i++) {
        //     char c = num[i] ;
        //     s = s + c ;
        //     integer = stoi(s) ;
        //     if (integer % 2 == 1){
        //         Max = max(Max , integer) ;
        //     }
        //     else {
        //         continue ;
        //     }
        // }
        // if (Max == INT_MIN){
        //     return "" ;
        // }
        // return to_string(Max) ;
        int n = num.length();
        for (int i = n - 1; i >= 0; i--) {
            char c = num[i];
            if ((c - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};