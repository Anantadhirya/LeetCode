class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> v(n);
        vector<string> ans(n);
        for(int i = 0; i < n; i++) {
            v[i] = {score[i], i};
        }
        sort(v.begin(), v.end());
        if(n >= 1) ans[v[n-1].second] = "Gold Medal";
        if(n >= 2) ans[v[n-2].second] = "Silver Medal";
        if(n >= 3) ans[v[n-3].second] = "Bronze Medal";
        for(int i = 4; i <= n; i++) {
            ans[v[n-i].second] = to_string(i);
        }
        return ans;
    }
};