class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int l = 1, r = *max_element(nums.begin(), nums.end()), mid, cnt, ans;
        while(l <= r) {
            mid = (l+r)/2;
            cnt = 0;
            for(auto &i: nums) {
                cnt += (i+mid-1)/mid - 1;
            }
            if(cnt <= maxOperations) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};