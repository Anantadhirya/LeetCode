class Solution {
public:
    int f(int x) {
        int ret = 0;
        while(x > 0) {
            ret += x%10;
            x /= 10;
        }
        return ret;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int &i: nums) {
            ans = min(ans, f(i));
        }
        return ans;
    }
};