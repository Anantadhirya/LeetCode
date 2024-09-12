class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        bitset<26> v = 0;
        int ans = 0;
        bool valid;
        for(const auto &i: allowed) {
            v[i-'a'] = 1;
        }
        for(const auto &word: words) {
            valid = 1;
            for(const auto &i: word) {
                if(!v[i-'a']) {
                    valid = 0;
                    break;
                }
            }
            ans += valid;
        }
        return ans;
    }
};