class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int idx = nums.size()-1;
        bitset<100> cnt;
        while(idx >= 0 && !cnt[nums[idx]]) cnt[nums[idx--]] = 1;
        return idx == -1 ? 0 : idx/3 + 1;
    }
};