class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = *max_element(nums.begin(), nums.end());
        for(int l = 0, r = ans, mid, cnt; l <= r; ) {
            mid = (l+r)/2;
            cnt = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] <= mid) {
                    cnt++;
                    i++;
                }
            }
            if(cnt >= k) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};