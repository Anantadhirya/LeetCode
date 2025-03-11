class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int lst[3], ans = 0;
        lst[0] = lst[1] = lst[2] = -1;
        for(int i = 0; i < n; i++) {
            lst[s[i]-'a'] = i;
            ans += min(lst[0], min(lst[1], lst[2])) + 1;
        }
        return ans;
    }
};