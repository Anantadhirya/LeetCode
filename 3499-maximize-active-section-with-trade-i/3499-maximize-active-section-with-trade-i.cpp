class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = "1" + s + "1";
        vector<int> v;
        int n = s.size();
        v.push_back(1);
        int cnt = -1, ans;
        for(int i = 1; i < n; i++) {
            if(s[i] != s[i-1]) v.push_back(0);
            v.back()++;
            if(s[i] == '1') cnt++;
        }
        ans = cnt;
        for(int i = v.size()-2; i-2 >= 0; i -= 2) {
            ans = max(ans, cnt + v[i] + v[i-2]);
        }
        return ans;
    }
};