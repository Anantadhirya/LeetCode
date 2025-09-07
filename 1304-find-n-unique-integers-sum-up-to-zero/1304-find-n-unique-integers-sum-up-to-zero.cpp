class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);
        for(int i = 0; i+1 < n; i += 2) {
            ans[i] = i/2 + 1;
            ans[i+1] = -(i/2 + 1);
        }
        return ans;
    }
};