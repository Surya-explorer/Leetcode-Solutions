class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n  = nums.size() ;
        map<int , int> map ;
        for (int i = 0 ; i< n ; i++){
            map[nums[i]] ++ ;
        }
        vector <int> ans ;
        for (auto i = map.begin() ; i != map.end() ; i++){
            if(i->second > (n/3)){
                ans.push_back(i->first) ;
            }
        }
        return ans ;
    }
};