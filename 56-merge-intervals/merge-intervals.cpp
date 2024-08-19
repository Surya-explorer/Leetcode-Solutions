class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // if (intervals.size() == 0 || intervals.size() == 1 ){
            
        //     return {intervals[0]} ;
        // }
        sort (intervals.begin() ,  intervals.end()) ;
        vector <vector <int>> ans ;
        ans.push_back(intervals[0]) ;
        for  (int i = 1 ; i < intervals.size() ; i++){
            if (ans.back()[1] > intervals[i][0]){
                if (ans.back()[1] <= intervals[i][1]){
                    ans.back()[1] = intervals[i][1] ;
                }
                
            }
            else if (ans.back()[1] == intervals[i][0]){
                ans.back()[1] = intervals[i][1] ;
            }
            else {
                ans.push_back(intervals[i]) ;
            }
        } 
        return ans ;
    }
};