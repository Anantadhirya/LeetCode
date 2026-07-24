class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int m = (1<<(32-__builtin_clz(mx)));
        bitset<2048> b1, b2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                b1[nums[i] ^ nums[j]] = 1;
            }
            for(int j = 0; j < m; j++) {
                if(b1[j]) b2[j^nums[i]] = 1;
            }
        }
        return b2.count();
    }
};