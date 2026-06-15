class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        long long ans = 0, ans2 = k;
        for(int i = 0; i < n; i++) {
            ans += abs((long long)arr[i] - brr[i]);
        }
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        for(int i = 0; i < n; i++) {
            ans2 += abs((long long)arr[i] - brr[i]);
        }
        return min(ans, ans2);
    }
};