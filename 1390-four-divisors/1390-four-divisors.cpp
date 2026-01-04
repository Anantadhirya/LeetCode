class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0;
        vector<int> v(mx+1, 0);
        for(int i = 2; i <= mx; i++) {
            if(v[i] != 0) continue;
            for(long long j = (long long)i*i; j <= mx; j += i) {
                v[j] = i;
            }
        }
        for(auto i: nums)
            if(v[i] != 0 && (v[i/v[i]] == 0 && v[i] != i/v[i] || (long long)v[i]*v[i]*v[i] == i))
                ans += 1 + i + v[i] + i/v[i];
        return ans;
    }
};