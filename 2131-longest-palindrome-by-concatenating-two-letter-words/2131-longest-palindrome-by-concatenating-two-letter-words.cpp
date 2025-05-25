class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        string tmp;
        map<string, int> cnt;
        sort(words.begin(), words.end());
        for(const string &i: words) {
            tmp = string(1, i[1]) + i[0];
            if(cnt[tmp] > 0) {
                ans += 4;
                cnt[tmp]--;
            } else cnt[i]++;
        }
        for(const auto &[i, c]: cnt) {
            if(c > 0 && i[0] == i[1]) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};