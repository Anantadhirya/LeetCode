class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string mn, mx;
        mn = mx = strs[0];
        for(const string &s: strs) {
            mn = min(mn, s);
            mx = max(mx, s);
        }
        int ans = 0;
        int n = min(mn.size(), mx.size());
        for(int i = 0; i < n; i++) {
            if(mn[i] == mx[i]) ans = i+1;
            else break;
        }
        return mn.substr(0, ans);
    }
};