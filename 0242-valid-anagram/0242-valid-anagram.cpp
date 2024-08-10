class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};