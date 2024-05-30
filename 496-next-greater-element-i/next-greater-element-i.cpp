class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans ;
        
        for (int i = 0 ; i<nums1.size() ; i++){
            int j1 = 0   ;
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            if (it != nums2.end()) {
                j1 = distance(nums2.begin(), it);
            }
            for (int j = j1 ; j < nums2.size() ; j++ ){
                if (nums1[i] < nums2[j]){
                    ans.push_back(nums2[j]);
                    break ;
                }
            }
            if (ans.size() != i+1){
                ans.push_back(-1) ;
            }
        }
        return ans ;
    }
};