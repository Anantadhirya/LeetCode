class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int idx = 1;
        int i = 0, n = searchWord.size();
        for(const char &c: sentence) {
            if(c == ' ') i = 0, idx++;
            else {
                if(i != -1 && searchWord[i] == c) i++;
                else i = -1;
                if(i == n) return idx;
            }
        }
        return -1;
    }
};