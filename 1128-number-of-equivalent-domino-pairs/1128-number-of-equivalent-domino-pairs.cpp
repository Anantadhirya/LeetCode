class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0, idx;
        vector<int> cnt(100, 0);
        for(auto &i: dominoes) {
            if(i[0] > i[1]) swap(i[0], i[1]);
            idx = 10*i[0] + i[1];
            ans += cnt[idx];
            cnt[idx]++;
        }
        return ans;
    }
};