class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(vector<int>(i+1, 1));
            for(int j = 1; j <= i; j++) {
                ans[i][j] = (j < i ? ans[i-1][j] : 0) + ans[i-1][j-1];
            }
        }
        return ans;
    }
};