class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if(k == 0) return ans;
        if(k > 0) {
            for(int i = 1; i <= k; i++) {
                ans[0] += code[i];
            }
            for(int i = 1; i < n; i++) {
                ans[i] = ans[i-1] + code[(i+k)%n] - code[i];
            }
        } else {
            for(int i = n+k; i <= n-1; i++) {
                ans[0] += code[i];
            }
            for(int i = 1; i < n; i++) {
                ans[i] = ans[i-1] + code[i-1] - code[(i+k-1+n)%n];
            }
        }
        return ans;
    }
};