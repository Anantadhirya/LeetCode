class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int x = mean * (m+n);
        vector<int> ans(n, 0);
        for(const auto &i: rolls) {
            x -= i;
        }
        if(x < n || 6*n < x) return {};
        for(int i = 0; i < n; i++) {
            ans[i] = (x/n) + (i < x%n);
        }
        return ans;
    }
};