class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int x = 0, i = 0; x <= n; x++) {
            while(i < n && nums[i] < x) i++;
            if(n - i == x) return x;
        }
        return -1;
    }
};