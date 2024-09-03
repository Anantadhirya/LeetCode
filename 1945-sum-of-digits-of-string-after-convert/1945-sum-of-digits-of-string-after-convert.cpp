class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0, tmp;
        for(const auto &i: s) {
            tmp = (i - 'a' + 1);
            ans += (tmp/10) + (tmp%10);
        }
        k--;
        while(k--) {
            s = to_string(ans);
            ans = 0;
            for(const auto &i: s) {
                ans += (i - '0');
            }
        }
        return ans;
    }
};