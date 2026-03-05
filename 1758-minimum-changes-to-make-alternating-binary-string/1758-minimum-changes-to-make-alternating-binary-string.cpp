class Solution {
public:
    int minOperations(string s) {
        int ans[] = {0, 0};
        for(int i = 0; i < s.size(); i++) {
            if(s[i]-'0' != (i&1)) ans[0]++;
            if(s[i]-'0' != (~i&1)) ans[1]++;
        }
        return min(ans[0], ans[1]);
    }
};