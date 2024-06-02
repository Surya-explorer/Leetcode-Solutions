class Solution {
public:
    // void solve (vector<int>& arr , vector<vector<int>> &ans ,vector<int> v,  int i  ){
    //     int n = arr.size() ;
    //     if (i == n){
    //         ans.push_back(v) ;
    //         return ;
    //     }
    //     int ele = arr[i] ;
    //     // Including the element
    //     v.push_back(ele) ;
        
    //     solve(arr , ans , v , i+1) ;
        
    //     // Excluding the element
    //     v.pop_back() ;
        
    //     while ( i+1 < n && arr[i] == arr[i+1]){
    //         i++ ;
    //         solve(arr , ans , v , i+1) ;
    //     }
    // }
    int sumSubarrayMins(vector<int>& arr) {
        // int sum = 0 ;
        // vector<vector<int>> ans ;
        // vector<int> v ;

        // solve (arr , ans , v ,  0 ) ;
        // for (int i = 0 ; i< ans.size() ; i++){
        //     // auto ele = min_element (ans[i].begin() , ans[i].end()) ;
        //     // if (ele != ans[i].end()){
        //     //     sum += *ele ;
        //     // }
        //     int Min = INT_MAX ;
        //     for (int j =0 ; j<ans[i].size() ; j++ ){
        //         Min = min (INT_MAX , ans[i][j]) ;
        //     }
        //     sum += Min ;
        // }
        // int mod = 1e7+ 10 ;
        // sum %= mod ;
        // return sum  ;





        int n = arr.size() ;
        int sum = 0 ;
        stack <pair  <int , int >> sleft , sright ;
        vector <int> left (n , 0 ) ;
        vector <int> right (n , 0 ) ;

    // Left array for storing no of left elements which are greater than this element .

        for (int i= 0 ; i< arr.size() ; i++){
            int cnt = 1 ;
            while(!sleft.empty() && sleft.top().first > arr[i]){    
                cnt += sleft.top().second ;
                sleft.pop() ;
            }
            sleft.push({arr[i] , cnt})  ; 
            left[i] = cnt ;
        }

    // Right array for storing no of Right elements which are greater than this element .
        for (int i = arr.size() -1 ; i>= 0 ; i--){
            int cnt = 1 ;
            while(!sright.empty() && sright.top().first >= arr[i]){    
                cnt += sright.top().second ;
                sright.pop() ;
            }
            sright.push({arr[i] , cnt})  ; 
            right[i] = cnt ;
        }

    int mod = 1e9 + 7 ;
    // Finding contributions of each elements in the minimum of the sub array .
        for (int i = 0 ; i < arr.size() ; i++){
            sum = ( sum +  (arr[i] * (long long)(left[i] *right[i])%mod)%mod)%mod  ;
        }
        return sum ;
    
    }


};