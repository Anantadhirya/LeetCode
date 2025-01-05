class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size(), shift = 0;
        vector<int> v(n+1, 0);
        for(const auto &i: shifts) {
            v[i[0]] += (i[2] ? 1 : -1);
            v[i[1]+1] += (i[2] ? -1 : 1);
        }
        for(int i = 0; i < n; i++) {
            (shift += v[i] % 26 + 26) %= 26;
            s[i] = (s[i]-'a'+shift)%26 + 'a';
        }
        return s;
    }
};