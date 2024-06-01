class Solution {
public:
    int trap(vector<int>& height) {
        int cnt  = 0  ;
        int  n = height.size() ;
        // for (int i = 0 ; i<= n-1 ; i++){
        //     int j = i ;
        //     int leftmax = 0 , rightmax = 0 ;
        //     while (j >= 0){
        //         leftmax = max (leftmax , height[j] ) ;
        //         j-- ;
        //     }
        //     j = i ;
        //     while (j < n){
        //         rightmax = max (rightmax , height[j] ) ;
        //         j++ ;
        //     }
            
        //     cnt += ( min(leftmax , rightmax) - height[i]) ;
        // }
        int left = 0 ;
        int right = n - 1 ;

        int leftmax = 0 , rightmax = 0 ;
        while (left < right) {
            if (height[left] < height[right]){
                if ( height[left] > leftmax){
                    leftmax = height[left] ;
                }
                else {
                    cnt += leftmax - height[left] ;
                }
                left++ ;
            }
            else {
                if ( height[right] > rightmax){
                    rightmax = height[right] ;
                }
                else {
                    cnt += rightmax - height[right] ;
                }

                right-- ;
            }
        }
        return cnt ;
    }
};