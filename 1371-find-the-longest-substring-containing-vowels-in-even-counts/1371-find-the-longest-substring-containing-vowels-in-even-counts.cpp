class Solution {
public:
    int findTheLongestSubstring(string s) {
        string vowels = "aiueo";
        vector<int> fi((1<<5), -1);
        int n = s.size(), ans = 0;
        fi[0] = 0;
        for(int i = 1, mask = 0; i <= n; i++) {
            for(int j = 0; j < 5; j++) {
                if(s[i-1] == vowels[j]) mask ^= (1<<j);
            }
            if(fi[mask] != -1) {
                ans = max(ans, i - fi[mask]);
            } else fi[mask] = i;
        }
        return ans;
    }
};