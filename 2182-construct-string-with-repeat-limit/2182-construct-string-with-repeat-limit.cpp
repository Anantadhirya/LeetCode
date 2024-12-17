class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26, 0);
        for(const auto &i: s) {
            cnt[i-'a']++;
        }
        string ans = "";
        for(int i = 25, j = 25; i >= 0; i--) {
            j = min(j, i-1);
            while(j >= 0 && cnt[j] == 0) j--;
            while(cnt[i] > repeatLimit && j != -1) {
                ans += string(repeatLimit, 'a'+i);
                ans.push_back('a'+j);
                cnt[i] -= repeatLimit;
                cnt[j]--;
                while(j >= 0 && cnt[j] == 0) j--;
            }
            if(cnt[i] > 0) ans += string(min(repeatLimit, cnt[i]), 'a'+i);
        }
        return ans;
    }
};