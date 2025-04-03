class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long mx = 0, mx2 = 0, ans = 0;
        for(const int &i: nums) {
            ans = max(ans, mx2 * i);
            mx2 = max(mx2, mx - i);
            mx = max(mx, (long long)i);
        }
        return ans;
    }
};