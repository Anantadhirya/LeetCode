class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<vector<int>> ans;
        int n = max(rows, cols);
        auto add = [&]() {
            if(0 <= rStart && rStart < rows && 0 <= cStart && cStart < cols) {
                ans.push_back({rStart, cStart});
            }
        };
        add();
        for(int i = 1; ans.size() != rows * cols; i += 2) {
            cStart++;
            add();
            for(int j = 1; j <= i; j++) {
                rStart++;
                add();
            }
            for(int j = 1; j <= i+1; j++) {
                cStart--;
                add();
            }
            for(int j = 1; j <= i+1; j++) {
                rStart--;
                add();
            }
            for(int j = 1; j <= i+1; j++) {
                cStart++;
                add();
            }
        }
        return ans;
    }
};