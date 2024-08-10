class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> cnt;
        for(const auto &i: magazine) {
            cnt[i]++;
        }
        for(const auto &i: ransomNote) {
            if(cnt[i] == 0) return 0;
            cnt[i]--;
        }
        return 1;
    }
};