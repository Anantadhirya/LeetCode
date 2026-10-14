class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        int n = words.size();
        map<string, bool> ada;
        ada[""] = 1;
        pair<int, string> ans = {0, ""};
        string tmp;
        for(string &s: words) {
            tmp = s;
            s.pop_back();
            if(ada[s]) {
                ans = min(ans, {-tmp.size(), tmp});
                ada[tmp] = 1;
            }
        }
        return ans.second;
    }
};