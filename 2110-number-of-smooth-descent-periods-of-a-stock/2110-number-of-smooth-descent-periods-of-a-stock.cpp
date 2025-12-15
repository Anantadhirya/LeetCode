class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        for(int i = 0, j = 0; i < n; i++) {
            if(i-1 >= 0 && prices[i-1] != prices[i] + 1) j = i;
            ans += (long long)(i-j+1);
        }
        return ans;
    }
};