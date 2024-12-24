class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> m(26, -1);
        int cnt = 0;
        for(const auto &i: key) {
            if(i == ' ' || m[i-'a'] != -1) continue;
            m[i-'a'] = cnt++;
        }
        for(auto &i: message) {
            if(i == ' ') continue;
            i = 'a' + m[i-'a'];
        }
        return message;
    }
};