class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     int product=1;
        bool flag=false;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)product*=nums[i];
            else{
                flag=true;
                c++;
            }
        }

        if(c==nums.size()){
                    vector<int> res(nums.size(), 0);
            return res;
        }
        if(c>1){
            vector<int> res(nums.size(), 0);
            return res;
        }
                vector<int> res;
        for(int i=0;i<nums.size();i++){
            
            if(!flag) res.push_back(product/nums[i]);
            else {
                if(nums[i]==0)res.push_back(product);
                else res.push_back(0);
            }
        }
        return res;
    }
};