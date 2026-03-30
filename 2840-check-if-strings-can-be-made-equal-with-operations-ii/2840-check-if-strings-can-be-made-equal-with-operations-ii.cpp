class Solution {
public:
    pair<string, string> split(string &s) {
        string ret[2];
        int n = s.size();
        for(int i = 0; i < n; i++) {
            ret[i&1] += s[i];
        }
        return {ret[0], ret[1]};
    }
    bool checkStrings(string s1, string s2) {
        pair<string, string> p1 = split(s1), p2 = split(s2);
        sort(p1.first.begin(), p1.first.end());
        sort(p1.second.begin(), p1.second.end());
        sort(p2.first.begin(), p2.first.end());
        sort(p2.second.begin(), p2.second.end());
        return p1 == p2;
    }
};