class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = chalk.size();
        long long sm = 0;
        for(const auto &i: chalk) {
            sm += (long long)i;
        }
        k %= sm;
        for(int i = 0; i < n; i++) {
            if(k < chalk[i]) return i;
            k -= chalk[i];
        }
        return 0;
    }
};