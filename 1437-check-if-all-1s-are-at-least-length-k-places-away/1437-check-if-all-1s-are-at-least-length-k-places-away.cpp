class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lst = -1, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i]) {
                if(lst != -1 && i - lst - 1 < k) return 0;
                lst = i;
            }
        }
        return 1;
    }
};