class Solution {
public:
    bool parseBoolExpr(string expression) {
        vector<vector<char>> v(1);
        string s;
        char tmp;
        for(const auto &i: expression) {
            if(i != ',') s.push_back(i);
        }
        for(const auto &i: s) {
            if(i == '(') {
                tmp = v.back().back();
                v.back().pop_back();
                v.push_back({tmp});
            } else if(i == ')') {
                if(v.back()[0] == '!') {
                    tmp = v.back()[1] == 't' ? 'f' : 't';
                } else if(v.back()[0] == '&') {
                    tmp = 't';
                    for(const auto &j: v.back()) {
                        if(j == 'f') {
                            tmp = 'f';
                            break;
                        }
                    }
                } else if(v.back()[0] == '|') {
                    tmp = 'f';
                    for(const auto &j: v.back()) {
                        if(j == 't') {
                            tmp = 't';
                            break;
                        }
                    }
                }
                v.pop_back();
                v.back().push_back(tmp);
            } else v.back().push_back(i);
        }
        return v[0][0] == 't';
    }
};