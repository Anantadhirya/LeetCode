class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int mx = 0;
        int tmp, ans = 0;
        for(const auto &i: candidates) {
            mx = max(mx, i);
        }
        for(; mx > 0; mx /= 2) {
            tmp = 0;
            for(int &i: candidates) {
                tmp += (i&1);
                i /= 2;
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};