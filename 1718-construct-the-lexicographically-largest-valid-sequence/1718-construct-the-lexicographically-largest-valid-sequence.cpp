/*
1
2 1 2
3 1 2 3 2
4 2 3 2 4 3 1
5 3 1 4 3 5 2 4 2
6 4 2 5 2 4 6 3 5 2 3 2
7 5 3 6 4 3 5 7 4 6 2 1 2
8 6 4 2 . 2 4 6 8
*/
class Solution {
public:
    bool solve(int idx, int &n, vector<int> &ans, vector<bool> &used) {
        if(idx == 2*n-1) return 1;
        if(ans[idx] != -1) return solve(idx+1, n, ans, used);
        for(int i = n; i >= 1; i--) {
            if(used[i]) continue;
            if(i != 1 && idx+i >= 2*n-1) continue;
            if(i != 1 && ans[idx+i] != -1) continue;
            ans[idx] = ans[idx+i-(i==1)] = i;
            used[i] = 1;
            if(solve(idx+1, n, ans, used)) return 1;
            ans[idx] = ans[idx+i-(i==1)] = -1;
            used[i] = 0;
        }
        return 0;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1, -1);
        vector<bool> used(n+1, 0);
        solve(0, n, ans, used);
        return ans;
    }
};