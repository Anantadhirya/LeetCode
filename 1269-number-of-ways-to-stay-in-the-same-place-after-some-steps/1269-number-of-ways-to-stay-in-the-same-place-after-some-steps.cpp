class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp(int step, int pos, int &arrLen, vector<vector<int>> &memo) {
        if(step == 0) return (pos == 0);
        if(pos < 0 || pos >= arrLen) return 0;
        if(memo[step][pos] != -1) return memo[step][pos];
        int &ret = memo[step][pos];
        ret = dp(step-1, pos-1, arrLen, memo);
        (ret += dp(step-1, pos, arrLen, memo)) %= MOD;
        (ret += dp(step-1, pos+1, arrLen, memo)) %= MOD;
        return ret;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> memo(steps+1, vector<int>(steps+1, -1));
        return dp(steps, 0, arrLen, memo);
    }
};