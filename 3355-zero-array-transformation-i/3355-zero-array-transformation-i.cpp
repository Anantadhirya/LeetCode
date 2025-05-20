class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> v(n+1, 0);
        for(const auto &i: queries) {
            v[i[0]]++;
            v[i[1]+1]--;
        }
        int pref = 0;
        for(int i = 0; i < n; i++) {
            pref += v[i];
            if(pref < nums[i]) return 0;
        }
        return 1;
    }
};