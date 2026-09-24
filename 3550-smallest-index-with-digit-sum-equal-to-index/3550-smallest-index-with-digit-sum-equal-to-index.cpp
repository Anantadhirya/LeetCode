class Solution {
public:
    int f(int n) {
        int ret = 0;
        while(n > 0) ret += n%10, n /= 10;
        return ret;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(f(nums[i]) == i) return i;
        }
        return -1;
    }
};