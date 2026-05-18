class Solution {
public:
    long long maximumTotalSum(vector<int>& h) {
        int n = h.size();
        sort(h.begin(), h.end());
        long long ans = h.back();
        for(int i = n-2; i >= 0; i--) {
            h[i] = min(h[i], h[i+1] - 1);
            if(h[i] <= 0) return -1;
            ans += (long long)h[i];
        }
        return ans;
    }
};