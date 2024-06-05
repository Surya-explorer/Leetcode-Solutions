class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size() ;
        if (k >= n) return "0"; 
        stack <char> st ; 
        for (int i = 0 ; i< num.size() ; i++ ){
            // char ch = num.charAt(i) ;
            while (!st.empty()  &&  num[i] < st.top() && k > 0){
                st.pop() ;
                k-- ;
            } 
            if( !st.empty() || num[i] != '0') st.push(num[i])    ;    
        }      
        // If the string is in increasing order , k would not have decresed .
        // This mean all the bigger numbers are placed at the end .
        
        while (k>0 && !st.empty() ) {
            st.pop() ;
            k-- ;
        }

        string ans(st.size() , ' ') ;
        for (int i = st.size()-1 ; i >= 0 ; i-- ){
            ans[i] = st.top() ;
            st.pop() ;
        }

        // Skipping if there is leading zeros  
        int d = 0 ;
        while (d < ans.size() && ans[d] == '0' ) d++ ;
        ans = (d == ans.size()) ? "0" : ans.substr(d);
        return ans ;
    }
};