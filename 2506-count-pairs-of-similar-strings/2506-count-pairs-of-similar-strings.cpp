class Solution {
public:
    int similarPairs(vector<string>& words) {
        int mask, ans = 0;
        unordered_map<int, int> cnt;
        for(const auto &word: words) {
            mask = 0;
            for(const auto &c: word) {
                mask |= (1<<(c-'a'));
            }
            ans += cnt[mask]++;
        }
        return ans;
    }
};