class Solution {
public:
    int maximumUniqueSubarray(vector<int>& arr) {
        int ans = 0, tmp = 0;
        vector<int> cnt(1e4 + 5, 0);
        for(int l = 0, r = 0; r < arr.size(); r++) {
            tmp += arr[r];
            cnt[arr[r]]++;
            while(cnt[arr[r]] > 1) {
                tmp -= arr[l];
                cnt[arr[l]]--;
                l++;
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};