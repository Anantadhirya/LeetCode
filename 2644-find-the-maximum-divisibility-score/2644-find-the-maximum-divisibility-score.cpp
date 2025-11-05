class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        pair<int, int> ans = {1, -1};
        int cnt;
        for(auto i: divisors) {
            cnt = 0;
            for(auto j: nums) cnt += (j % i == 0);
            ans = min(ans, {-cnt, i});
        }
        return ans.second;
    }
};