class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        string ans = "";
        int n = s.size(), m = spaces.size();
        for(int i = 0, j = 0; i < n; i++) {
            if(j < m && spaces[j] == i) ans += ' ', j++;
            ans += s[i];
        }
        return ans;
    }
};