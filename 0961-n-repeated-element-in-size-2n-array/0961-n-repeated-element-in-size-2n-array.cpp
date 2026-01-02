class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> m;
        for(int i = 0; i < n; i++) {
            if(m[nums[i]]) return nums[i];
            m[nums[i]] = 1;
        }
        return -1;
    }
};