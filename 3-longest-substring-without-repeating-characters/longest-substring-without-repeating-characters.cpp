class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // unordered_map<char, int> mp;
        // int cnt = 0;
        // if (s.empty())
        //     return 0;
        // if (s.size() == 1)
        //     return 1;
        // int index = 0;

        vector <int > dict (256 , -1) ;
        int ans = 0;
        int start = -1 ;
        for (int i = 0; i < s.size(); i++) {
            
            if (dict[s[i]] > start) start = dict[s[i]] ;
            dict[s[i]] = i ;

            ans = max (ans , i - start) ;
        }
        return ans;
    }
};