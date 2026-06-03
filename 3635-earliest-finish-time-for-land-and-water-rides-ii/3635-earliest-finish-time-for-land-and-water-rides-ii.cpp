class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int l = INT_MAX, w = INT_MAX, ans = INT_MAX;
        int n = ls.size(), m = ws.size();
        for(int i = 0; i < n; i++) {
            l = min(l, ls[i] + ld[i]);
        }
        for(int i = 0; i < m; i++) {
            w = min(w, ws[i] + wd[i]);
        }
        for(int i = 0; i < n; i++) {
            ans = min(ans, max(w, ls[i]) + ld[i]);
        }
        for(int i = 0; i < m; i++) {
            ans = min(ans, max(l, ws[i]) + wd[i]);
        }
        return ans;
    }
};