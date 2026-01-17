class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        long long ans = 0;
        int n = bottomLeft.size();
        long long l, r, b, t, tmp;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                l = max(bottomLeft[i][0], bottomLeft[j][0]);
                r = min(topRight[i][0], topRight[j][0]);
                b = max(bottomLeft[i][1], bottomLeft[j][1]);
                t = min(topRight[i][1], topRight[j][1]);
                if(l <= r && b <= t) {
                    tmp = min(r-l, t-b);
                    ans = max(ans, tmp * tmp);
                }
            }
        }
        return ans;
    }
};