class Solution {
public:
    int inv(int x) {
        int ret = 0;
        while(x > 0) ret = 10*ret + x%10, x /= 10;
        return ret;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        map<int, int> lst;
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(lst.count(nums[i])) ans = min(ans, i-lst[nums[i]]);
            lst[inv(nums[i])] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};