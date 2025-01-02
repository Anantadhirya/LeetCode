class Solution {
public:
    int maxScore(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = s.size();
        int left = 0, right = 0, ans = 0;
        for(const int &i: s) {
            right += (i == '1');
        }
        for(int i = 0; i < n-1; i++) {
            left += (s[i] == '0');
            right -= (s[i] == '1');
            ans = max(ans, left + right);
        }
        return ans;
    }
};