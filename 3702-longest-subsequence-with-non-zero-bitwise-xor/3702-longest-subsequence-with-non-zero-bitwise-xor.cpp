class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int x = 0, nonzero = 0;
        for(int &i: nums) {
            x ^= i;
            if(i != 0) nonzero++;
        }
        if(x != 0) return n;
        if(nonzero != 0) return n-1;
        return 0;
    }
};