class Solution {
public:
    string maximumBinaryString(string binary) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int cnt = 0, n = binary.size();
        string ans(n, '1');
        if(ans == binary) return ans;
        bool zeros = 0;
        for(const auto &c: binary) {
            if(c == '1') {
                cnt += zeros;
            } else zeros = 1;
        }
        if(cnt != n) ans[n-cnt-1] = '0';
        return ans;
    }
};