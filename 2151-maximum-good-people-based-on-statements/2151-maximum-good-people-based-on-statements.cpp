class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;

        auto check = [&](int mask) -> bool {
            for(int i = 0; i < n; i++) {
                if((mask>>i)&1) {
                    for(int j = 0; j < n; j++) {
                        if(statements[i][j] == 2) continue;
                        if(statements[i][j] != ((mask>>j)&1)) return 0;
                    }
                }
            }
            return 1;
        };

        for(int mask = 0, valid; mask < (1<<n); mask++) {
            if(check(mask)) ans = max(ans, __builtin_popcount(mask));
        }
        return ans;
    }
};