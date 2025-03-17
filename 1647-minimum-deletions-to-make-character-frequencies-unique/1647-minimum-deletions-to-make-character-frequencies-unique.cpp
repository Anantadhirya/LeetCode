class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26, 0);
        for(const auto &i: s) {
            cnt[i-'a']++;
        }
        vector<int> v;
        for(int i = 0; i < 26; i++) {
            v.push_back(cnt[i]);
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 26 - 2, to; i >= 0; i--) {
            if(v[i] >= v[i+1]) {
                to = max(0, v[i+1] - 1);
                ans += (v[i] - to);
                v[i] = to;
            }
        }
        return ans;
    }
};