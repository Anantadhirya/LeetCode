class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        map<char, string> m;
        map<string, char> m2;
        int n = pattern.size();
        v.push_back("");
        for(const char &c: s) {
            if(c == ' ') v.push_back("");
            else v.back().push_back(c);
        }
        if(n != v.size()) return 0;
        for(int i = 0; i < n; i++) {
            if(m.count(pattern[i]) && m[pattern[i]] != v[i]) return 0;
            if(m2.count(v[i]) && m2[v[i]] != pattern[i]) return 0;
            m[pattern[i]] = v[i];
            m2[v[i]] = pattern[i];
        }
        return 1;
    }
};