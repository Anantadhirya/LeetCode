class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> ans(2005, 0), ans2(2005, 0);
        ans[1000] = 1;
        for(auto &i: nums) {
            swap(ans, ans2);
            for(int j = 0; j <= 2000; j++) {
                ans[j] = 0;
                if(j - i >= 0) ans[j] += ans2[j-i];
                if(j + i <= 2000) ans[j] += ans2[j+i];
            }
        }
        return ans[target+1000];
    }
};