class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<vector<int>> cnt(2, vector<int>(26, 0));
        for(int i = 0; i < n; i++) {
            cnt[i&1][s1[i]-'a']++;
            cnt[i&1][s2[i]-'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[0][i] != 0 || cnt[1][i] != 0) return 0;
        }
        return 1;
    }
};