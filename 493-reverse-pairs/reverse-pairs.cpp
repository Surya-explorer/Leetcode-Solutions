class Solution {
public:

    int merger (vector <int> &nums , int low ,  int mid , int high ){
        int cnt = 0 ;
        int j = mid + 1 ;
        for (int i = low ; i <= mid ; i++){
            while (j <= high && nums[i] > 2LL * nums[j] ) {
                j++ ;
            }
            cnt += j-(mid+1) ;
        }
        // Merging of the sorted array .

        vector <int > temp ;
        int left = low ;
        int right = mid + 1 ;

        while (left <= mid && right <= high){
            if(nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }

        while (left <= mid)  temp.push_back(nums[left++]);
        while (right<= high)  temp.push_back(nums[right++]);


        for (int i =  low ; i <= high ; i++){
            nums[i]  = temp[i- low] ;
        }
        return cnt ;
    }

    int merge (vector <int> &nums , int low , int high){
        if (low >= high) return 0 ;
        int mid = (low + high)/2  ;

        int ans = 0 ;
        ans = merge (nums , low , mid);
        ans += merge (nums , mid + 1 , high ) ;
        ans += merger(nums , low , mid , high) ;

        return ans ; 
    }
    int reversePairs(vector<int>& nums) {
        return merge ( nums , 0 , nums.size() -1 ) ;
    }
};