class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> exp = heights;
        sort(exp.begin(), exp.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (heights[i] != exp[i]);
        }
        return ans;
    }
};