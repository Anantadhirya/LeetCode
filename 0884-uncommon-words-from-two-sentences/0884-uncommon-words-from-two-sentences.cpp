class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> split1(1, ""), split2(1, "");
        for(const auto &i: s1) {
            if(i == ' ') split1.push_back("");
            else split1.back() += i;
        }
        for(const auto &i: s2) {
            if(i == ' ') split2.push_back("");
            else split2.back() += i;
        }
        map<string, int> s;
        for(const auto &i: split1) {
            s[i]++;
        }
        for(const auto &i: split2) {
            s[i]++;
        }
        vector<string> ans;
        for(const auto &[i, c]: s) {
            if(c == 1) ans.push_back(i);
        }
        return ans;
    }
};