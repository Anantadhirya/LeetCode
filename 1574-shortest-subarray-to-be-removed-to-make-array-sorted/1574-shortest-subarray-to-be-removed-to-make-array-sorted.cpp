class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1, ans;
        while(l+1 < n && arr[l] <= arr[l+1]) l++;
        while(r-1 >= 0 && arr[r-1] <= arr[r]) r--;
        ans = n-1-l;
        if(l == n-1) return 0;
        for(int tmp; r < n; r++) {
            tmp = upper_bound(arr.begin(), arr.begin() + l + 1, arr[r]) - arr.begin();
            ans = min(ans, max(0, r - tmp));
        }
        return ans;
    }
};