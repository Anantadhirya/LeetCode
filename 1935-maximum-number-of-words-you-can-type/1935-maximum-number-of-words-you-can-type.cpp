class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        string word = "";
        text.push_back(' ');
        int ans = 0;
        bitset<26> b;
        for(const char &c: brokenLetters) b.set(c-'a');
        for(const char &c: text) {
            if(c == ' ') {
                ans++;
                for(const char &i: word) {
                    if(b[i-'a']) {
                        ans--;
                        break;
                    }
                }
                word = "";
            } else word += c;
        }
        return ans;
    }
};