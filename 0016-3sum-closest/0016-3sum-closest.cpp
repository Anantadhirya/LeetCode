class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        set<int> s;
        int n = nums.size();
        pair<int, int> ans = {INT_MAX, 0};
        for(int i = 0; i < n; i++) {
            for(int j = i+1, k; j < n; j++) {
                k = nums[i] + nums[j];
                auto it = s.lower_bound(target-k);
                if(it != s.end()) {
                    ans = min(ans, {abs(target - ((*it) + k)), (*it)+k});
                }
                if(it != s.begin()) {
                    it--;
                    ans = min(ans, {abs(target - ((*it) + k)), (*it)+k});
                }
            }
            s.insert(nums[i]);
        }
        return ans.second;
    }
};