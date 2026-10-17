class Solution {
public:
    int digitsum(int x) {
        int ret = 0;
        while(x > 0) {
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 3>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {digitsum(nums[i]), nums[i], i};
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            while(v[i][2] != i) {
                swap(v[i], v[v[i][2]]);
                ans++;
            }
        }
        return ans;
    }
};