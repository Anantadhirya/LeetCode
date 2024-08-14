class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums.back() - nums[0], mid, ans = -1;
        int check;
        while(l <= r) {
            mid = (l+r)/2;
            check = 0;
            for(int i = 0, j = 0; i < n; i++) {
                while(nums[i] - nums[j] > mid) j++;
                check += i-j;
            }
            if(check >= k) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};