class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        const int MOD = 1e9 + 7;
        for(int i = 1; i < n; i++) {
            if(complexity[0] < complexity[i]) continue;
            return 0;
        }
        int ans = 1;
        for(int i = 1; i < n; i++) {
            ans = (long long)ans * i % MOD;
        }
        return ans;
    }
};