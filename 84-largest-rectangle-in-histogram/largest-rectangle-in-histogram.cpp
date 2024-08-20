class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0 ;
        stack <int > s ;
        for (int i = 0 ; i < heights.size() ; i++){
            while (!s.empty() && heights[s.top()] > heights[i]){
                int h = heights[s.top()] ;
                s.pop() ;
                int  w = s.empty() ? i : i- s.top() - 1 ;
                int area = h* w ;
                maxarea = max(maxarea ,  area );
            }
            s.push(i) ;
        }
        int n = heights.size() ;
        while (!s.empty()){
            int h = heights[s.top()] ;
            
            s.pop() ;
            int  w = s.empty() ? n :  n - s.top() - 1 ;
            maxarea = max(maxarea , h * w  ) ;            
        }
        return maxarea ;
    }
};



// if (heights.size() == 1 ) return heights[0] ;
//         if (heights.size() == 0 ) return 0  ;
//         for (int i = 0 ; i+1 < heights.size() ; i++){
//             if ( heights[i] <= heights[i+1]){
//                 int index = i+1 ;
//                 while (index < heights.size()  && heights[i] <= heights[index] ){
//                     index++ ;
//                 }
//                 int area = heights[i] *(index-i) ;
//                 maxarea = max(maxarea , area   )  ;
//             }
//             else {
//                 int area1 = min(heights[i] , heights[i+1]) * 2 ;
//                 maxarea = max(maxarea , area1 )  ;
                
//             }
//             minheight = min (minheight , heights[i]) ;
//             minheight = min (minheight , heights[i+1]) ;
            
//             int area2 = min(heights[i] , heights[i+1]) * 2 ;
//             maxarea = max(maxarea  , area2 ) ;
            
//             maxarea = max(maxarea  , heights[i]) ;
//             maxarea = max(maxarea  , heights[i+1]) ;
            
//         }
//         int allarea = minheight*(heights.size()) ;
//         maxarea = max(maxarea  , allarea ) ;
















