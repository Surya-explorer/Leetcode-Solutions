class Solution {
public:
    void Solve ( string digits , int index , vector <string > & ans ,
    string Output , string Mapping[]  ) {
        // Base Case  : -
        if ( index >= digits.size()) {
            if (digits.size() > 0 ) {
                ans.push_back(Output) ;  
            }
            return ; 
        }
        int number = digits[index] - '0' ;
        string val = Mapping[number] ; 

        for ( int i =  0 ; i< val.length() ; i++) {
            Output.push_back (val[i]) ;
            Solve(digits , index +1 , ans , Output ,Mapping) ;
            Output.pop_back() ;
        } 
    }
    vector<string> letterCombinations(string digits) {
        int index = 0 ;
        vector <string> ans  ;
        string Output  ;
        string Mapping[10] = {"","" ,"abc" ,"def","ghi" ,"jkl","mno" ,"pqrs","tuv","wxyz"} ;
        Solve(digits , index , ans , Output , Mapping ) ;
        return ans  ;
    }
};