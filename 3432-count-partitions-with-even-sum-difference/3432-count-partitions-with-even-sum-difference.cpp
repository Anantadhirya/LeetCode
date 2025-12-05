class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sm = 0, pref = 0, ans = 0;
        for(int i: nums) sm += i;
        for(int i: nums) {
            pref += i;
            ans += (abs((sm - pref) - pref) % 2 == 0);
        }
        ans -= (sm % 2 == 0);
        return ans;
    }
};