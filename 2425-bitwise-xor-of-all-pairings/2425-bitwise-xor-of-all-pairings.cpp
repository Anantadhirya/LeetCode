class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0, ans = 0, n = nums1.size(), m = nums2.size();
        for(const int &i: nums1) {
            xor1 ^= i;
        }
        for(const int &i: nums2) {
            xor2 ^= i;
        }
        if(m&1) ans ^= xor1;
        if(n&1) ans ^= xor2;
        return ans;
    }
};