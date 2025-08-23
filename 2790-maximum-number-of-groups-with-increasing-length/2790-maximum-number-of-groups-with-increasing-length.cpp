class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        long long total = 0, ans = 0;
        for(const int &i: usageLimits) {
            total += (long long)i;
            if(total >= (ans+1)*(ans+2) / 2) ans++;
        }
        return ans;
    }
};