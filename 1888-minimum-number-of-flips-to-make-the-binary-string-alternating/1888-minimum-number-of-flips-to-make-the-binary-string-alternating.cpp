class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int cnt[2] = {0, 0};
        int ans = n;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') cnt[i&1]++; 
        }
        for(int i = 0; i < n; i++) {
            ans = min(ans, ((n+1)/2 - cnt[0]) + cnt[1]);
            ans = min(ans, cnt[0] + (n/2 - cnt[1]));
            if(s[i] == '1') {
                cnt[0]--;
                cnt[n&1]++;
            }
            swap(cnt[0], cnt[1]);
        }
        return ans;
    }
};