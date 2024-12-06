class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int ans = 0, m = banned.size();
        sort(banned.begin(), banned.end());
        for(int i = 1, j = 0; i <= n; i++) {
            if(j < m && banned[j] == i) {
                while(j < m && banned[j] == i) j++;
                continue;
            }
            if(i <= maxSum) {
                maxSum -= i;
                ans++;
            } else break;
        }
        return ans;
    }
};