class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int cnt1 = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') cnt1++;
            else {
                if(i-1 >= 0 && s[i-1] == '0') continue;
                ans += cnt1;
            }
        }
        return ans;
    }
};