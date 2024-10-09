class Solution {
public:
    int minAddToMakeValid(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int cnt = 0, ans = 0;
        for(const auto &i: s) {
            if(i == '(') {
                cnt++;
            } else {
                if(cnt) cnt--;
                else ans++;
            }
        }
        return ans + cnt;
    }
};