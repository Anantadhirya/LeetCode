class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        for(int l = 0, r = n-1, mid; l <= r; ) {
            mid = (l+r)/2;
            if(nums[mid] < nums[0]) {
                idx = mid;
                r = mid-1;
            } else l = mid+1;
        }
        return nums[idx];
    }
};