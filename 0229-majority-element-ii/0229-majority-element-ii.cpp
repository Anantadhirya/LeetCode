class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n/3;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0, j = 0; i < n; i = j) {
            while(j < n && nums[j] == nums[i]) j++;
            if(j - i > k) ans.push_back(nums[i]);
        }
        return ans;
    }
};