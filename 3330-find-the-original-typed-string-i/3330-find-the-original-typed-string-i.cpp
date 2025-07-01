const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size(), ans = 1;
        for(int i = 1; i < n; i++) {
            ans += (word[i] == word[i-1]);
        }
        return ans;
    }
};