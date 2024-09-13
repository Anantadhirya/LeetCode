class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = arr.size();
        vector<int> pref(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] ^ arr[i-1];
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            ans[i] = pref[queries[i][1]+1] ^ pref[queries[i][0]];
        }
        return ans;
    }
};