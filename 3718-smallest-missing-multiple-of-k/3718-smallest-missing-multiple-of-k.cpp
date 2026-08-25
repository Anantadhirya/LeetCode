class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bitset<101> b;
        for(int &i: nums) b.set(i);
        for(int i = k; ; i += k) {
            if(i <= 100 && b[i]) continue;
            return i;
        }
    }
};