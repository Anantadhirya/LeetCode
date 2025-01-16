class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int cnt1, cnt2, cnt, ans = 0, n = nums1.size(), m = nums2.size();
        for(int i = 0; i < 30; i++) {
            cnt1 = cnt2 = 0;
            for(const auto &j: nums1) {
                cnt1 += ((j>>i)&1);
            }
            for(const auto &j: nums2) {
                cnt2 += ((j>>i)&1);
            }
            cnt = (cnt1 * (m - cnt2)) + (cnt2 * (n - cnt1));
            ans += (cnt&1) * (1<<i);
        }
        return ans;
    }
};