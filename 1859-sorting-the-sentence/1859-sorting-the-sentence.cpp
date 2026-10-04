class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int, string>> v(1);
        string ans;
        for(char &c: s) {
            if(c == ' ') v.push_back({0, ""});
            else {
                if('0' <= c && c <= '9') v.back().first = (c-'0');
                else v.back().second += c;
            }
        }
        sort(v.begin(), v.end());
        for(auto &[_, i]: v) {
            if(!ans.empty()) ans.push_back(' ');
            ans += i;
        }
        return ans;
    }
};