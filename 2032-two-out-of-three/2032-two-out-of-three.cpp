class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> v(101, 0);
        for(const int &i: nums1) v[i] |= 1;
        for(const int &i: nums2) v[i] |= 2;
        for(const int &i: nums3) v[i] |= 4;
        vector<int> ans;
        for(int i = 1; i <= 100; i++) {
            if(__builtin_popcount(v[i]) >= 2) ans.push_back(i);
        }
        return ans;
    }
};