class Solution {
public:
    char kthCharacter(int k) {
        string s = "a", tmp;
        while(s.size() < k) {
            tmp = s;
            for(auto &i: s) {
                tmp.push_back('a' + (i - 'a' + 1) % 26);
            }
            s = tmp;
        }
        return s[k-1];
    }
};