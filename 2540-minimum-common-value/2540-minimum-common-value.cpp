class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int j = 0, n = nums2.size();
        for(const auto &i: nums1) {
            while(j < n && nums2[j] < i) j++;
            if(j < n && nums2[j] == i) return i;
        }
        return -1;
    }
};