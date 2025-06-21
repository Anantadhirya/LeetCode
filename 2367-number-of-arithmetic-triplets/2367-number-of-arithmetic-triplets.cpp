class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0, j = 0, k = 0; i < n; i++) {
            while(j < n && nums[j] < nums[i] + diff) j++;
            while(k < n && nums[k] < nums[i] + 2*diff) k++;
            if(k >= n) break;
            ans += (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff);
        }
        return ans;
    }
};