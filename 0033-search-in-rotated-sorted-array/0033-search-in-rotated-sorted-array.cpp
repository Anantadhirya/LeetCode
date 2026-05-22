class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = 0;
        int n = nums.size();
        for(int l = 0, r = n-1, mid; l <= r; ) {
            mid = (l+r)/2;
            if(nums[mid] < nums[0]) {
                k = mid;
                r = mid-1;
            } else l = mid+1;
        }
        for(int l = 0, r = n-1, mid, idx; l <= r; ) {
            mid = (l+r)/2;
            idx = (mid+k)%n;
            if(nums[idx] == target) return idx;
            else if(nums[idx] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};