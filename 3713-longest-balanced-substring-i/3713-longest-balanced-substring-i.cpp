class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> cnt(26);
        int mx;
        bool balanced;
        for(int i = 0; i < n; i++) {
            cnt.assign(26, 0);
            mx = 0;
            for(int j = i; j >= 0; j--) {
                mx = max(mx, ++cnt[s[j]-'a']);
                balanced = 1;
                for(int k = 0; k < 26; k++) {
                    if(cnt[k] > 0 && cnt[k] != mx) {
                        balanced = 0;
                        break;
                    }
                }
                if(balanced) ans = max(ans, i-j+1);
            }
        }
        return ans;
    }
};