class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = n-1; i >= 0; i--) {
            for(int x = nums[i]; x > 0; x /= 10) {
                ans.push_back(x%10);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};