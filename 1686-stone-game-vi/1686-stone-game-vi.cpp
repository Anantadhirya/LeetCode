class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {aliceValues[i] + bobValues[i], i};
        }
        sort(v.begin(), v.end());
        int diff = 0;
        for(int i = n-1; i >= 0; i -= 2) {
            diff += aliceValues[v[i].second];
        }
        for(int i = n-2; i >= 0; i -= 2) {
            diff -= bobValues[v[i].second];
        }
        return diff >= 0 ? diff > 0 ? 1 : 0 : -1;
    }
};