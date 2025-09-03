class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, cur = 0;
        for(const int &i: nums) {
            if(i ^ cur == 0) cur ^= 1, ans++;
        }
        return ans;
    }
};