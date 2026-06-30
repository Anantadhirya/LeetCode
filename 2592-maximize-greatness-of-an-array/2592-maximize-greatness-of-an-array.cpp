class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = n-1, j = n-1; i >= 0; i--) {
            if(nums[i] < nums[j]) {
                ans++;
                j--;
            }
        }
        return ans;
    }
};