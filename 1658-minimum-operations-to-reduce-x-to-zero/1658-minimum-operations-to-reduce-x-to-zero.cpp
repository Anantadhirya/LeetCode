class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int, int> m;
        int sm = 0;
        int n = nums.size();
        int ans = INT_MAX, tmp;
        m[0] = 0;
        for(int i = n-1; i >= 0; i--) {
            sm += nums[i];
            m[sm] = n-i;
        }
        sm = 0;
        if(m.count(x)) ans = min(ans, m[x]);
        for(int i = 0; i < n; i++) {
            sm += nums[i];
            if(m.count(x - sm)) {
                tmp = i+1 + m[x-sm];
                if(tmp <= n) ans = min(ans, tmp);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};