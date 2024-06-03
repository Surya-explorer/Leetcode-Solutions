class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0 ;
        
        for (int i = 0 ; i< nums.size() ; i++){
            // int Max = INT_MIN ;
            // int Min = INT_MAX ;
            int Max = nums[i];
            int Min = nums[i] ;
            for (int j = i ; j <nums.size() ;j++ ){
                Max = max(Max , nums[j] ) ;
                Min = min(Min , nums[j] ) ;
                sum+= Max - Min ;
            }
        }

        return sum ;
    }
};









//     int n = arr.size() ;
    //     int sum = 0 ;
    //     stack <pair  <int , int >> sleft1 , sright1 ;
    //     stack <pair  <int , int >> sleft2 , sright2 ;
    //     vector <int> left (n , 0 ) ;
    //     vector <int> right (n , 0 ) ;

    // // Left array for storing no of left elements which are greater than this element .
    //     for (int i= 0 ; i< arr.size() ; i++){
    //         int lcnt = 1 ;
    //         int rcnt = 1 ;
    //         if (sleft.top().first > arr[i]){
    //             while(!sleft.empty()){    
    //                 lcnt += sleft.top().second ;
    //                 sleft.pop() ;
    //             }
    //         }
    //         else if (sleft.top().first < arr[i]){
    //             while(!sleft.empty()){    
    //                 rcnt += arr[i] ;
    //                 sleft.pop() ;
    //             }
    //         }
    //         sleft1.push({arr[i] , cnt})  ; 
    //         sleft2.push({arr[i] , cnt})  ; 
    //         left[i] = cnt ;
    //     }

    // // Right array for storing no of Right elements which are greater than this element .
    //     for (int i = arr.size() -1 ; i>= 0 ; i--){
    //         int cnt = 1 ;
    //         while(!sright.empty() && sright.top().first >= arr[i]){    
    //             cnt += sright.top().second ;
    //             sright.pop() ;
    //         }
    //         sright.push({arr[i] , cnt})  ; 
    //         right[i] = cnt ;
    //     }