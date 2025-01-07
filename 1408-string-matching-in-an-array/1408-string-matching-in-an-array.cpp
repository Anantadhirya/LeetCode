class Solution {
public:
    bool isSubstring(string &a, string &b) {
        if(a.size() > b.size()) return 0;
        for(int i = b.size()-a.size(), valid; i >= 0; i--) {
            valid = 1;
            for(int j = a.size()-1; j >= 0; j--) {
                if(a[j] != b[i+j]) {
                    valid = 0;
                    break;
                }
            }
            if(valid) return 1;
        }
        return 0;
    }
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j != i && isSubstring(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};