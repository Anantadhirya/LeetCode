class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        unordered_map<int, int> cnt;
        for(const auto &i: nums1) {
            cnt[i]++;
        }
        vector<int> ans;
        for(const auto &i: nums2) {
            if(cnt[i]) {
                ans.push_back(i);
                cnt[i]--;
            }
        }
        return ans;
    }
};