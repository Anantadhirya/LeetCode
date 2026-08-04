class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        bitset<101> b;
        vector<int> ans;
        int mn = nums[0], mx = nums[0];
        for(int &i: nums) {
            b.set(i);
            mn = min(mn, i);
            mx = max(mx, i);
        }
        for(int i = mn; i <= mx; i++) {
            if(!b[i]) ans.push_back(i);
        }
        return ans;
    }
};