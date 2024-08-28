class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size() ;
        map <int , int> mp ;

        for (int i =  0 ; i < size ; i++){
            mp[nums[i]]++ ;
            if (mp[nums[i]] >1 ) return nums[i] ;
        }
        return -1 ;
    }
};