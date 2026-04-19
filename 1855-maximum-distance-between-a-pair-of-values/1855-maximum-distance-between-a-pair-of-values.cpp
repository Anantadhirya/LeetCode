class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ans = 0;
        for(int i = 0, j = 0; i < n; i++) {
            while(j < m && nums1[i] <= nums2[j]) j++;
            if(i <= j-1) ans = max(ans, j-1 - i);
        }
        return ans;
    }
};