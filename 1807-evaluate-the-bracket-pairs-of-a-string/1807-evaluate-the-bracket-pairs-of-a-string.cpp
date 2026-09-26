class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> m;
        for(auto &i: knowledge) {
            m[i[0]] = i[1];
        }
        bool bracket = 0;
        string ans, tmp;
        for(char &c: s) {
            if(c == '(') bracket = 1, tmp = "";
            else if(c == ')') {
                bracket = 0;
                if(m.count(tmp)) ans += m[tmp];
                else ans += "?";
            } else {
                if(bracket) tmp.push_back(c);
                else ans.push_back(c);
            }
        }
        return ans;
    }
};