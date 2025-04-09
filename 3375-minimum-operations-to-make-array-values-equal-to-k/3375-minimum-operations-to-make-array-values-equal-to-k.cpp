class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s(nums.begin(), nums.end());
        int mn = *s.begin();
        if(k > mn) return -1;
        return s.size() - (k == mn);
    }
};