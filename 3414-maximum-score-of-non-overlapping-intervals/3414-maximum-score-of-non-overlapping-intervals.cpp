#define LL long long
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<pair<LL, vector<int>>>> dp(n+1, vector<pair<LL, vector<int>>>(5, {1, {}}));
        pair<LL, vector<int>> tmp, ans;
        for(int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        dp[n][0] = {0, {}};
        for(int i = n-1, k; i >= 0; i--) {
            k = n;
            for(int l = i+1, r = n-1, mid; l <= r; ) {
                mid = (l+r)/2;
                if(intervals[i][1] < intervals[mid][0]) {
                    k = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }
            for(int j = 0; j <= 4; j++) {
                // Case tidak dipilih
                dp[i][j] = dp[i+1][j];

                // Case dipilih
                if(j == 0) continue;
                tmp = dp[k][j-1];
                if(tmp.first == 1) continue;
                tmp.first += (LL)-intervals[i][2];
                tmp.second.push_back(intervals[i][3]);
                for(int idx = tmp.second.size()-1; idx-1 >= 0; idx--) {
                    if(tmp.second[idx-1] < tmp.second[idx]) break;
                    swap(tmp.second[idx-1], tmp.second[idx]);
                }

                // Merge
                dp[i][j] = min(dp[i][j], tmp);
            }
        }
        ans = dp[0][0];
        for(int j = 0; j <= 4; j++) {
            ans = min(ans, dp[0][j]);
        }
        return ans.second;
    }
};