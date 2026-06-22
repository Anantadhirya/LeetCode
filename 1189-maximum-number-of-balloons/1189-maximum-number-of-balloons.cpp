class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26, 0);
        int ans;
        for(char &c: text) {
            cnt[c-'a']++;
        }
        ans = cnt['b'-'a'];
        ans = min(ans, cnt['a'-'a']);
        ans = min(ans, cnt['l'-'a']/2);
        ans = min(ans, cnt['o'-'a']/2);
        ans = min(ans, cnt['n'-'a']);
        return ans;
    }
};