class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> ans;
        unordered_map<int, int> cnt;
        for(const auto &i: nums) {
            cnt[i]++;
        }
        for(const auto &[u, v]: cnt) {
            if(v == 1) ans.push_back(u);
        }
        return ans;
    }
};