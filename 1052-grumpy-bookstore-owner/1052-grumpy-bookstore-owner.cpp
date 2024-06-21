class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = customers.size();
        int ans = 0, tmp = 0;
        for(int i = 0, j = 0; i < n; i++) {
            if(grumpy[i]) tmp += customers[i];
            if(i-j >= minutes) {
                if(grumpy[j]) tmp -= customers[j];
                j++;
            }
            ans = max(ans, tmp);
        }
        for(int i = 0; i < n; i++) {
            if(!grumpy[i]) ans += customers[i];
        }
        return ans;
    }
};