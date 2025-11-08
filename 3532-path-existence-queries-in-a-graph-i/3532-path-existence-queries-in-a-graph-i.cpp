class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> v(n);
        vector<int> pref(n);
        vector<bool> ans;
        int a, b;
        for(int i = 0; i < n; i++) {
            pref[i] = (i-1 >= 0 ? pref[i-1] : 0) + (i+1 < n ? nums[i+1] - nums[i] <= maxDiff : 0);
        }
        for(auto i: queries) {
            a = i[0];
            b = i[1];
            if(a > b) swap(a, b);
            ans.push_back((b-1 >= 0 ? pref[b-1] : 0) - (a-1 >= 0 ? pref[a-1] : 0) == b-a);
        }
        return ans;
    }
};