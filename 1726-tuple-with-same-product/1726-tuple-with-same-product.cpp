class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        map<int, int> m;
        for(int i = 0, p; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                ans += m[nums[i] * nums[j]]++;
            }
        }
        return 8*ans;
    }
};