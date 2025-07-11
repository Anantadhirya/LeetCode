class Solution {
public:
    bool checkIfPangram(string sentence) {
        bitset<26> b;
        for(const char &c: sentence) {
            b[c-'a'] = 1;
        }
        return b.count() == 26;
    }
};