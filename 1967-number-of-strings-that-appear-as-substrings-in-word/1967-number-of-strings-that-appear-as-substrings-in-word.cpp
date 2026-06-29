class Solution {
public:
    bool is_sub(string &word, string &s) {
        bool match;
        for(int i = 0; i+s.size()-1 < word.size(); i++) {
            match = 1;
            for(int j = 0; j < s.size(); j++) {
                if(word[i+j] != s[j]) match = 0;
            }
            if(match) return 1;
        }
        return 0;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(auto &s: patterns) {
            ans += is_sub(word, s);
        }
        return ans;
    }
};