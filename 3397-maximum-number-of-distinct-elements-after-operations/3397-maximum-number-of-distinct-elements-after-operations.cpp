const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int ans = 0, cur = INT_MIN;
        sort(nums.begin(), nums.end());
        for(const int &i: nums) {
            if(cur+1 < i-k) cur = i-k, ans++;
            else if(cur+1 <= i+k) cur++, ans++;
        }
        return ans;
    }
};