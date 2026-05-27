class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> v(26, 0);
        int ans = 0;
        for(char &c: word) {
            if('a' <= c && c <= 'z') {
                if(v[c-'a'] == 0) v[c-'a'] = 1;
                else if(v[c-'a'] == 1) continue;
                else v[c-'a'] = -1;
            } else if('A' <= c && c <= 'Z') {
                if(v[c-'A'] == 1) v[c-'A'] = 2;
                else if(v[c-'A'] == 2) continue;
                else v[c-'A'] = -1;
            }
        }
        for(int i = 0; i < 26; i++) ans += (v[i] == 2);
        return ans;
    }
};