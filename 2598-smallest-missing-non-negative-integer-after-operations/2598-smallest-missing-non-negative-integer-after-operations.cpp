class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> cnt(value, 0);
        for(auto i: nums) {
            cnt[((i%value)+value)%value]++;
        }
        int n = nums.size();
        for(int i = 0; i <= n; i++) {
            if(cnt[i%value]) cnt[i%value]--;
            else return i;
        }
        return n;
    }
};