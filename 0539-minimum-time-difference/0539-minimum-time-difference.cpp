class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> v;
        for(const auto &i: timePoints) {
            v.push_back(stoi(i.substr(0,2))*60 + stoi(i.substr(3, 2)));
        }
        sort(v.begin(), v.end());
        int n = v.size();
        int ans = 24*60 + v[0] - v[n-1];
        for(int i = 0; i+1 < n; i++) {
            ans = min(ans, v[i+1] - v[i]);
        }
        return ans;
    }
};