class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> idx;
        for(int i = 0; i < n; i++) {
            if(idx.count(target-nums[i])) {
                return {idx[target-nums[i]], i};
            }
            idx[nums[i]] = i;
        }
        return {-1, -1};
    }
};