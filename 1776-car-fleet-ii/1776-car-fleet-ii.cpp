class Solution {
public:
    double intersect(pair<int, int> a, pair<int, int> b) {
        return ((double)b.first-a.first)/(a.second-b.second);
    }
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1);
        pair<int, int> cur;
        vector<pair<int, int>> v;
        for(int i = n-1; i >= 0; i--) {
            cur = {cars[i][0], cars[i][1]};
            while(!v.empty() && v.back().second >= cur.second) v.pop_back();
            while(v.size() >= 2 && intersect(cur, v.back()) > intersect(v.back(), v[v.size()-2])) v.pop_back();
            ans[i] = (v.empty() ? -1 : intersect(cur, v.back()));
            v.push_back(cur);
        }
        return ans;
    }
};