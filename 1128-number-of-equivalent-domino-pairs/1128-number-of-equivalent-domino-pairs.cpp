class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        map<vector<int>, int> cnt;
        for(auto &i: dominoes) {
            if(i[0] > i[1]) swap(i[0], i[1]);
            ans += cnt[i];
            cnt[i]++;
        }
        return ans;
    }
};