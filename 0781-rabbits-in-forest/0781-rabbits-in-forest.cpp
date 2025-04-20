class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for(const auto &i: answers) {
            cnt[i]++;
        }
        for(const auto &[i, c]: cnt) {
            ans += ((c-1) / (i+1) + 1) * (i+1);
        }
        return ans;
    }
};