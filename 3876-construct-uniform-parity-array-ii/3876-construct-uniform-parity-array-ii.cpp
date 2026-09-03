class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = INT_MAX;
        for(int &i: nums1) {
            if(i&1) mn = min(mn, i);
        }
        if(mn == INT_MAX) return 1;
        for(int &i: nums1) {
            if(i%2 == 0) i -= mn;
            if(i < 1) return 0;
        }
        return 1;
    }
};