class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size(), k = q.size();
        int ans = 0;
        bitset<1001> b;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) continue;
            b = 1;
            for(int j = 0; j < k; j++) {
                if(q[j][0] <= i && i <= q[j][1]) b |= (b << q[j][2]);
                if(b[nums[i]]) {
                    ans = max(ans, j+1);
                    break;
                }
            }
            if(!b[nums[i]]) return -1;
        }
        return ans;
    }
};