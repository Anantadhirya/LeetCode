class Solution {
public:
    bool match(string &a, string &b, int &n) {
        int diff = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) diff++;
        }
        return diff <= 2;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        bool valid;
        int n = queries[0].size();
        for(string &s: queries) {
            valid = 0;
            for(string &t: dictionary) {
                if(match(s, t, n)) {
                    valid = 1;
                    break;
                }
            }
            if(valid) ans.push_back(s);
        }
        return ans;
    }
};