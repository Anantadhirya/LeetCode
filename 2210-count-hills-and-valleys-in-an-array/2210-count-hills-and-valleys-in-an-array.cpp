class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 1, j; i < n-1; i = j) {
            j = i+1;
            while(j < n-1 && nums[j] == nums[i]) j++;
            if((nums[i-1] < nums[i] && nums[i] > nums[j]) || (nums[i-1] > nums[i] && nums[i] < nums[j])) ans++;
        }
        return ans;
    }
};