class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int inf = INT_MAX;
        vector<vector<int>> mn(3, vector<int>(2, inf));
        int ans = 0, tmp = inf;
        for(auto i: nums) {
            ans += i;
            mn[i%3].push_back(i);
            if(mn[i%3].size() >= 3 && mn[i%3][2] < mn[i%3][1]) swap(mn[i%3][2], mn[i%3][1]);
            if(mn[i%3].size() >= 2 && mn[i%3][1] < mn[i%3][0]) swap(mn[i%3][1], mn[i%3][0]);
            if(mn[i%3].size() == 3) mn[i%3].pop_back();
        }
        if(ans%3 != 0) {
            if(mn[ans%3][0] != inf) tmp = min(tmp, mn[ans%3][0]);
            if(mn[3-ans%3][1] != inf) tmp = min(tmp, mn[3-ans%3][0] + mn[3-ans%3][1]);
            if(tmp == inf) return 0;
            ans -= tmp;
        }
        return ans;
    }
};