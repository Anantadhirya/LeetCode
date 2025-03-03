class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, pivot);
        int l = 0, r = n-1;
        for(const auto &i: nums) {
            if(i == pivot) continue;
            if(i < pivot) ans[l++] = i;
            else ans[r--] = i;
        }
        for(int i = r+1, j = n-1; i < j; i++, j--) {
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};