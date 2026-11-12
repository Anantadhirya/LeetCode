class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        vector<int> cnt(2, 0);
        for(auto &i: position) {
            cnt[i%2]++;
        }
        return min(cnt[0], cnt[1]);
    }
};