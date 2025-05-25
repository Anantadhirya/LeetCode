class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int tmp, inv;
        vector<int> cnt(26*26, 0);
        for(const string &i: words) {
            tmp = (i[0]-'a')*26 + (i[1]-'a');
            inv = (i[1]-'a')*26 + (i[0]-'a');
            if(cnt[inv] > 0) {
                ans += 4;
                cnt[inv]--;
            } else cnt[tmp]++;
        }
        for(int i = 0; i < 26; i++) {
            tmp = i*26 + i;
            if(cnt[tmp] > 0) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};