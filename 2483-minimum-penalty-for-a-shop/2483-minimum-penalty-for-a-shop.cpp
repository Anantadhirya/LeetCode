class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), cnt = 0, tmp = 0;
        pair<int, int> ans;
        for(char c: customers) cnt += (c == 'Y');
        ans = {cnt, 0};
        for(int i = 0; i < n; i++) {
            tmp += (customers[i] == 'Y');
            ans = min(ans, {(i+1-tmp) + (cnt-tmp), i+1});
        }
        return ans.second;
    }
};