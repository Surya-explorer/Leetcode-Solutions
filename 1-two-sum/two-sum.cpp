class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector <int> ans ;
        int i = 0 ;
        int j = 1 ;
        for ( ; i<nums.size() ; ){
            if (j== nums.size()){
                i++ ;
                j = i+ 1 ;
            }
            if (nums[i] + nums[j] == target ){
                return {i ,j} ;
            }
            else{
                j++ ;
            }
        }
        return {} ;
    }
};