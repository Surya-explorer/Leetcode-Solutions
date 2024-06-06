class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ;
        vector <int > left(n) ;     
        vector <int > right(n)  ;
        stack <int> st ;

        // finding left smaller elements
        for (int i = 0 ; i < heights.size() ; i++){ 
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop() ;
            } 
            if (st.empty()) left[i] = 0 ;
            else left[i] = st.top() + 1 ;
            st.push(i) ;
        }  
        
        // Removing Left numbers in stack .
        while (!st.empty() ) st.pop() ;
        
        // finding right smaller elements
        for (int i = heights.size()-1 ; i >= 0 ; i--){     
            while  (!st.empty() && heights[st.top()] >= heights[i]){
                st.pop() ;
            } 
            if (st.empty()) right[i] = n-1 ;
            else right[i] = st.top() - 1 ;
            // right[i] = (st.empty()) ? n - 1 : st.top() - 1;
            st.push(i) ;
        }     
        int Max = 0 ;
        for (int i =  0 ; i < n ; i++){
            int ele = (right[i] - left[i] + 1) ;

            Max = max ( Max , ele * heights[i])  ;
        } 
        return Max ;
    }
};