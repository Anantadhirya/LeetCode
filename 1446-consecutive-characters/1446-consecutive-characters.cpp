class Solution {
public:
    int maxPower(string s) {
        int n = s.size(), ans = 0, tmp = 0;
        for(int i = 0; i < n; i++) {
            if(i-1 >= 0 && s[i] != s[i-1]) tmp = 0;
            ans = max(ans, ++tmp);
        }
        return ans;
    }
};