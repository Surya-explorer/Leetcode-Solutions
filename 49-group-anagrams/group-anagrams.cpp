class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans ;

        map <string , vector <string>  >  mp ;
        for (int i = 0 ; i < strs.size() ;i++){
            string s = strs[i] ;
            string st = strs[i] ;
            sort (s.begin() , s.end()) ;
            
            // Pushing the unsorted string in vector
            mp[s].push_back(st) ;
        }

        for (auto i : mp){
            ans.push_back(i.second) ;
        }
        
        return ans ;
    }
};