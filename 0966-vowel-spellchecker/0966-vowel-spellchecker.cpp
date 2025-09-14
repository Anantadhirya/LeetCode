class Solution {
public:
    bool vocal(char c) {
        return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        map<string, string> ans, ans2, ans3;
        string tmp;
        for(const string &s: wordlist) {
            if(!ans.count(s)) ans[s] = s;
        }
        for(const string &s: wordlist) {
            tmp = s;
            for(char &c: tmp) c = tolower(c);
            if(!ans2.count(tmp)) ans2[tmp] = s;
        }
        for(const string &s: wordlist) {
            tmp = s;
            for(char &c: tmp) {
                c = tolower(c);
                if(vocal(c)) c = '.';
            }
            if(!ans3.count(tmp)) ans3[tmp] = s;
        }
        for(string &s: queries) {
            if(ans.count(s)) {
                s = ans[s];
                continue;
            }
            for(char &c: s) c = tolower(c);
            if(ans2.count(s)) {
                s = ans2[s];
                continue;
            }
            for(char &c: s) c = vocal(c) ? '.' : c;
            if(ans3.count(s)) {
                s = ans3[s];
                continue;
            }
            s = "";
        }
        return queries;
    }
};