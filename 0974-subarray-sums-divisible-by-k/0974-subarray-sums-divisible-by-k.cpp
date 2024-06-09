class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> v(k, 0);
        int tmp = 0, ans = 0;
        v[0] = 1;
        for(const int &i: nums) {
            tmp = ((tmp + i) % k + k) % k;
            ans += v[tmp];
            v[tmp]++;
        }
        return ans;
    }
};