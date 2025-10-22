const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<int> values;
        for(int &i: nums) {
            values.push_back(i-k);
            values.push_back(i);
            values.push_back(i+k);
        }
        int n = nums.size();
        int i = 0, j = 0, l = 0, r = 0;
        sort(nums.begin(), nums.end());
        sort(values.begin(), values.end());
        int ans = 0;
        for(int &val: values) {
            while(i < n && nums[i] < val) i++;
            while(j < n && nums[j] <= val) j++;
            while(l < n && nums[l] < val-k) l++;
            while(r < n && nums[r] <= val+k) r++;
            ans = max(ans, (j-i) + min(numOperations, (r-l) - (j-i)));
        }
        return ans;
    }
};