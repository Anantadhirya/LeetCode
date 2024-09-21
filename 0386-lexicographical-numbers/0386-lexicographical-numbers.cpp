class Solution {
public:
    void solve(int curr, int &n, vector<int> &ans) {
        if(curr > n) return;
        if(curr) {
            ans.push_back(curr);
        }
        for(int i = 0; i <= 9; i++) {
            if(curr || i) solve(10*curr + i, n, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> ans;
        solve(0, n, ans);
        return ans;
    }
};