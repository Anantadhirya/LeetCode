class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int tmp1 = 0, tmp2 = 1;
        int n = nums1.size();
        for(int i = 0; i < n-1; i++) {
            if(nums1[i] > nums1[n-1] || nums2[i] > nums2[n-1]) {
                tmp1++;
                if(nums1[i] > nums2[n-1] || nums2[i] > nums1[n-1]) return -1;
            }
            if(nums1[i] > nums2[n-1] || nums2[i] > nums1[n-1]) {
                tmp2++;
                if(nums1[i] > nums1[n-1] || nums2[i] > nums2[n-1]) return -1;
            }
        }
        return min(tmp1, tmp2);
    }
};