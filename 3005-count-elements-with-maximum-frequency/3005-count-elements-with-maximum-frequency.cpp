class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int mx = 0, ans = 0;
        for(const int &i: nums) {
            cnt[i]++;
        }
        for(const auto &[u, v]: cnt) {
            if(v > mx) {
                mx = v;
                ans = 0;
            }
            if(v == mx) ans += v;
        }
        return ans;
    }
};