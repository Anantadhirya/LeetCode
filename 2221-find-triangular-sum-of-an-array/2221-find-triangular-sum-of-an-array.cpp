class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> v[2];
        v[0] = v[1] = nums;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n-i; j++) {
                v[i&1][j] = (v[~i&1][j] + v[~i&1][j+1]) % 10;
            }
        }
        return v[~n&1][0];
    }
};