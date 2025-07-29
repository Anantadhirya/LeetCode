class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 1);
        for(int j = 0; j <= 30; j++) {
            for(int i = n-1, lst = -1; i >= 0; i--) {
                if((nums[i]>>j)&1) lst = i;
                if(lst != -1) v[i] = max(v[i], lst-i+1);
            }
        }
        return v;
    }
};