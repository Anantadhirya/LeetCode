class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bitset<1005> b;
        for(auto i: nums) b.set(i);
        while(original <= 1000 && b[original]) original *= 2;
        return original;
    }
};