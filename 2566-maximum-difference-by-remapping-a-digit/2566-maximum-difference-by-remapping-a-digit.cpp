class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int n = s.size(), idx1 = 0, idx2 = 0;
        char c1, c2;
        int mx = 0, mn = 0;
        while(idx1 < n && s[idx1] == '9') idx1++;
        while(idx2 < n && s[idx2] == '0') idx2++;
        c1 = (idx1 == n ? '9' : s[idx1]);
        c2 = (idx2 == n ? '0' : s[idx2]);
        for(int i = 0; i < n; i++) {
            mx = 10*mx + (s[i] == c1 ? 9 : s[i]-'0');
            mn = 10*mn + (s[i] == c2 ? 0 : s[i]-'0');
        }
        return mx - mn;
    }
};