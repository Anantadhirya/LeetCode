class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                triangle[i][j] += min((j <= i-1 ? triangle[i-1][j] : INT_MAX), (j-1 >= 0 ? triangle[i-1][j-1] : INT_MAX));
            }
        }
        ans = triangle[n-1][0];
        for(int i = 0; i < n; i++) {
            ans = min(ans, triangle[n-1][i]);
        }
        return ans;
    }
};