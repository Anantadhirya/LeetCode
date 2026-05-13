class Solution {
public:
    string f(string s) {
        string ret = "";
        for(char &c: s) {
            if(c == '#') {
                if(!ret.empty()) ret.pop_back();
            } else ret.push_back(c);
        }
        return ret;
    }
    bool backspaceCompare(string s, string t) {
        return f(s) == f(t);
    }
};