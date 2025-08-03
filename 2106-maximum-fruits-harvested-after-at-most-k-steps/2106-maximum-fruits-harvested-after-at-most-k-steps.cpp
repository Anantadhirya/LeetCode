class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size(), ans = 0, idx = 0;
        vector<int> pref(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + fruits[i-1][1];
            if(startPos >= fruits[i-1][0]) idx = i;
        }
        for(int i = 1, j = 1; i <= n && fruits[i-1][0] <= startPos; i++) {
            j = max(j, i);
            while(j <= n && startPos - fruits[i-1][0] + fruits[j-1][0] - fruits[i-1][0] <= k) j++;
            if(i < j) ans = max(ans, pref[max(idx, j-1)] - pref[i-1]);
        }
        for(int i = n, j = n; i >= 1 && startPos <= fruits[i-1][0]; i--) {
            j = min(j, i);
            while(j >= 1 && fruits[i-1][0] - startPos + fruits[i-1][0] - fruits[j-1][0] <= k) j--;
            if(j < i) ans = max(ans, pref[i] - pref[min(idx, j)]);
        }
        return ans;
    }
};