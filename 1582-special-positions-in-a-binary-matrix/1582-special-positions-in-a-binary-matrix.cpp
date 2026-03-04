class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        bool valid;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] != 1) continue;
                valid = true;
                for(int k = 0; k < mat.size() && valid; k++) {
                    if(k != i && mat[k][j] == 1) valid = false;
                }
                for(int k = 0; k < mat[i].size() && valid; k++) {
                    if(k != j && mat[i][k] == 1) valid = false;
                }
                ans += valid;
            }
        }
        return ans;
    }
};