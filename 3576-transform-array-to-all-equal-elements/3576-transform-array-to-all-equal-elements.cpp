class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, tmp1 = 1, tmp2 = 1;
        for(int i = 0; i+1 < n; i++) {
            if(nums[i] * tmp1 == -1) tmp1 = -1, cnt1++;
            else tmp1 = 1;
            if(nums[i] * tmp2 == 1) tmp2 = -1, cnt2++;
            else tmp2 = 1;
        }
        if(nums.back() * tmp1 == 1 && cnt1 <= k) return 1;
        if(nums.back() * tmp2 == -1 && cnt2 <= k) return 1;
        return 0;
    }
};