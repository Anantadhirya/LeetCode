class Solution {
public:
    bool check(vector<int>& nums, int &p, int x) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i+1 < nums.size() && nums[i+1] - nums[i] <= x) {
                ans++;
                i++;
            }
        }
        return ans >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int L = 0, R = nums.back() - nums[0], mid, ans;
        while(L <= R) {
            mid = L + R >> 1;
            if(check(nums, p, mid)) {
                ans = mid;
                R = mid - 1;
            } else L = mid + 1;
        }
        return ans;
    }
};