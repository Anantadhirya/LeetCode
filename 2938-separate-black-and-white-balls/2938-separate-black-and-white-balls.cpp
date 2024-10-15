class Solution {
public:
    long long minimumSteps(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        long long ans = 0, cnt = 0;
        for(const auto &i: s) {
            if(i == '1') cnt++;
            else ans += cnt;
        }
        return ans;
    }
};