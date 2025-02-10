class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for(const auto &c: s) {
            if('0' <= c && c <= '9') {
                ans.pop_back();
            } else ans += c;
        }
        return ans;
    }
};