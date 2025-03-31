class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> v(n-1);
        long long ans = 0;
        for(int i = 0; i+1 < n; i++) {
            v[i] = weights[i] + weights[i+1];
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < k-1; i++) {
            ans += v[n-2-i];
            ans -= v[i];
        }
        return ans;
    }
};