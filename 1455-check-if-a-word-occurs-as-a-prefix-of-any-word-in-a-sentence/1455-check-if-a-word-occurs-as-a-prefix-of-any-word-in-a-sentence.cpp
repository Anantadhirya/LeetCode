class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int idx = 1, j = 0, m = sentence.size();
        int i = 0, n = searchWord.size();
        for(; j < m; j++) {
            if(sentence[j] == ' ') i = 0, idx++;
            else {
                if(i != -1 && searchWord[i] == sentence[j]) i++;
                else i = -1;
                if(i == n) return idx;
            }
        }
        return -1;
    }
};