class Solution {
public:
    void solve(int l, int r, vector<int> &nums, vector<int> &tmp) {
        if(l >= r) return;
        int mid = (l+r)/2;
        solve(l, mid, nums, tmp);
        solve(mid+1, r, nums, tmp);
        for(int i = l, a = l, b = mid+1; i <= r; i++) {
            if(a > mid) tmp[i] = nums[b++];
            else if(b > r) tmp[i] = nums[a++];
            else if(nums[a] <= nums[b]) tmp[i] = nums[a++];
            else tmp[i] = nums[b++];
        }
        for(int i = l; i <= r; i++) {
            nums[i] = tmp[i];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tmp(nums.size());
        solve(0, nums.size()-1, nums, tmp);
        return nums;
    }
};