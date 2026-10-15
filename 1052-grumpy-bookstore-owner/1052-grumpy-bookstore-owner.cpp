class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0, tmp = 0;
        for(int i = 0; i < n; i++) {
            if(!grumpy[i]) {
                tmp += customers[i];
                customers[i] = 0;
            }
            if(i-1 >= 0) customers[i] += customers[i-1];
        }
        for(int i = 0; i+minutes-1 < n; i++) {
            ans = max(ans, tmp + customers[i+minutes-1] - (i-1 >= 0 ? customers[i-1] : 0));
        }
        return ans;
    }
};