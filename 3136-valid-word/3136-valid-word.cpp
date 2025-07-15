class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return 0;
        for(char &c: word) {
            if('0' <= c && c <= '9') continue;
            if('a' <= c && c <= 'z') continue;
            if('A' <= c && c <= 'Z') {
                c += 'a' - 'A';
                continue;
            }
            return 0;
        }
        bool vowel = 0, consonant = 0;
        for(char &c: word) {
            if('a' <= c && c <= 'z') {
                if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
                    vowel = 1;
                } else consonant = 1;
            }
        }
        return vowel && consonant;
    }
};