class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = names.size();
        vector<pair<int, string>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {heights[i], names[i]};
        }
        sort(v.begin(), v.end());
        vector<string> ret(n);
        for(int i = 0; i < n; i++) {
            ret[i] = v[n-i-1].second;
        }
        return ret;
    }
};