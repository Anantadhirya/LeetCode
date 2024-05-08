class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        long long pref = 0, x = 0, ans = 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            // (i+1)*x - pref <= k
            // x <= (pref+k)/(i+1)
            pref += (long long)nums[i];
            x = (pref+k)/(i+1);
            if(nums[i] <= x && (i+1 == n || x <= nums[i+1])) {
                k -= x*(i+1) - pref;
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] < x) {
                nums[i] = x;
            } else break;
        }
        for(int i = 0; i < n; i++) {
            (ans *= (long long)nums[i] + (i < k)) %= MOD;
        }
        return ans;
    }
};