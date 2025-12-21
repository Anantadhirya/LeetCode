class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), ans = 0;
        bool valid;
        vector<bool> v(n, 0);
        for(int j = 0; j < m; j++) {
            valid = 1;
            for(int i = 1; i < n; i++) {
                if(v[i]) continue;
                if(strs[i-1][j] > strs[i][j]) {
                    valid = 0;
                    break;
                }
            }
            if(!valid) ans++;
            else {
                for(int i = 1; i < n; i++) {
                    if(strs[i-1][j] < strs[i][j]) v[i] = 1;
                }
            }
        }
        return ans;
    }
};