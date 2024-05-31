class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
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