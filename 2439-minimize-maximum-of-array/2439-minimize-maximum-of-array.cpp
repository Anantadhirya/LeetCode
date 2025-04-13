class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = *max_element(nums.begin(), nums.end()), mid, ans;
        long long carry;
        while(l <= r) {
            mid = (l+r)/2;
            carry = 0;
            for(int i = n-1; i >= 1; i--) {
                carry = max((long long)0, (long long)nums[i] + carry - mid);
            }
            if(nums[0] + carry <= mid) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};