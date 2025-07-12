class Solution {
public:
    vector<int> base = {INT_MAX, INT_MIN};
    vector<int> solve(int n, int a, int b, vector<vector<vector<vector<int>>>> &memo) {
        vector<int> &ret = memo[n][a][b];
        if(ret != base) return ret;
        // a and b -> 0-based indexing
        if(a+b == n-1) return ret = {1, 1};
        int nn, aa, bb;
        bool awin, bwin;
        vector<int> tmp;
        nn = (n+1)/2;
        for(int mask = 0; mask < (1<<(n/2)); mask++) {
            aa = bb = awin = bwin = 0;
            for(int i = 0, win; i < (n+1)/2; i++) {
                if((mask>>i)&1) win = i;
                else win = n-1-i;

                if(win == a) awin = 1;
                if(win == b) bwin = 1;

                aa += (a > win);
                bb += (b > win);
            }
            if(!awin || !bwin) continue;
            tmp = solve(nn, aa, bb, memo);
            ret[0] = min(ret[0], tmp[0] + 1);
            ret[1] = max(ret[1], tmp[1] + 1);
        }
        return ret;
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<vector<vector<vector<int>>>> memo(n+1, vector<vector<vector<int>>>(n, vector<vector<int>>(n, base)));
        return solve(n, firstPlayer-1, secondPlayer-1, memo);
    }
};