class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> cnt(101, 0);
        for(int &i: nums) {
            if(i > n) return 0;
            if(cnt[i]++ > 0 && i != n) return 0;
        }
        return cnt[n] == 2;
    }
};