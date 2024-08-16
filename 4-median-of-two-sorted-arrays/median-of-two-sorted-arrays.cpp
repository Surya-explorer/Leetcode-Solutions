class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size() ;
        int n2 =  nums2.size() ;
        int ptr1 = 0 , ptr2 = 0 ;
        vector<int> nums;
        while (ptr1 != n1 &&  ptr2 != n2){
            if (nums1[ptr1] > nums2[ptr2]) {
                nums.push_back(nums2[ptr2]) ;
                ptr2++ ;
            }
            else{
                nums.push_back(nums1[ptr1]) ;
                ptr1++ ;
            }
        }
        if (ptr1 < n1 ){
            for (int i = ptr1 ; i < n1 ; i++) nums.push_back(nums1[i]) ;
        }
        if (ptr2 < n2 ){
            for (int i = ptr2 ; i < n2 ; i++) nums.push_back(nums2[i]) ;
        }

        float ans = 0 ;

        if (nums.size() % 2 == 0 ) {
            int a = nums.size()/2 ;
            ans = (nums[a] +  nums[a-1] )/2.0 ;
        }
        else {
            ans = float(nums[nums.size()/2]) ;
        }
        return ans ;
    }
};