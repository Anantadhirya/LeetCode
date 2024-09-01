class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int k = original.size();
        if(k != n*m) return {};
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i < k; i++) {
            ans[i/n][i%n] = original[i];
        }
        return ans;
    }
};