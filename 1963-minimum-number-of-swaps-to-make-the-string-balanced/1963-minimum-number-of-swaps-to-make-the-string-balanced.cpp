class Solution {
public:
    int minSwaps(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int cnt = 0, ans = 0;
        for(const auto &i: s) {
            if(i == '[') cnt++;
            else cnt--;
            if(cnt < 0) {
                ans++;
                cnt += 2;
            }
        }
        return ans;
    }
};