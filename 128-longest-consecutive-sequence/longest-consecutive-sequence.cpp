class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> st;
        for (int i = 0 ; i < nums.size() ; i++){
            st.insert(nums[i]) ;
        } 

        int j = 0 ;
        for (auto i : st) {
            nums[j++] = i ;
        }

        int cnt = 0 ;
        int ans = 0 ;
        if (nums.size() == 0 ) return 0 ;
        if (nums.size() == 1 ) return 1 ;
        for (int i = 0 ; i<= nums.size()-2 ;i++){
            if (nums[i+1] == nums[i] +1 ){
                cnt ++ ;
                ans = max (ans , cnt ) ;
            }
            else {
                cnt = 0 ;
            }
        }
        return ans + 1 ;
    }
};