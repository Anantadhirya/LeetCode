class Solution {
public:
    bool doesAliceWin(string s) {
        for(const char &c: s) {
            if(c == 'a' || c == 'i' || c =='u' || c == 'e' || c == 'o') return 1;
        }
        return 0;
    }
};