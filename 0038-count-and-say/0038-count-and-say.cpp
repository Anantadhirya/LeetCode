class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        vector<pair<char, int>> v;
        for(int i = 2; i <= n; i++) {
            v.clear();
            for(const auto &c: ans) {
                if(v.empty() || v.back().first != c) {
                    v.push_back({c, 0});
                }
                v.back().second++;
            }
            ans = "";
            for(const auto &[c, cnt]: v) {
                ans += to_string(cnt) + c;
            }
        }
        return ans;
    }
};