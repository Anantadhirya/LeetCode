class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        unordered_set<string> s(dictionary.begin(), dictionary.end());
        vector<string> split(1, "");
        string tmp, ans = "";
        bool found;
        for(const char &c: sentence) {
            if(c == ' ') split.push_back("");
            else split.back().push_back(c);
        }
        for(const string &word: split) {
            tmp = "";
            found = false;
            for(const char &c: word) {
                tmp.push_back(c);
                if(s.count(tmp)) {
                    found = true;
                    ans += tmp + " ";
                    break;
                }
            }
            if(!found) ans += tmp + " ";
        }
        ans.pop_back();
        return ans;
    }
};