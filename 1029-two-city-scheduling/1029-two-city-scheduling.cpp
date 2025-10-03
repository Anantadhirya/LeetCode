class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans = 0;
        int n = costs.size();
        vector<int> v;
        for(const auto &i: costs) {
            ans += i[0];
            v.push_back(i[1] - i[0]);
        }
        sort(v.begin(), v.end());
        n /= 2;
        for(int i = 0; i < n; i++) ans += v[i];
        return ans;
    }
};