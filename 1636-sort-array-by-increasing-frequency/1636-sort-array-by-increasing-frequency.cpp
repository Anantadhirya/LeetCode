class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        unordered_map<int, int> cnt;
        vector<pair<int, int>> v;
        vector<int> ret;
        for(const int &i: nums) {
            cnt[i]++;
        }
        for(const auto &[i, c]: cnt) {
            v.push_back({c, -i});
        }
        sort(v.begin(), v.end());
        for(const auto &[c, i]: v) {
            for(int j = c; j--; ) {
                ret.push_back(-i);
            }
        }
        return ret;
    }
};