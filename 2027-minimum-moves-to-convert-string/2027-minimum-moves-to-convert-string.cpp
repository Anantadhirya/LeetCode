class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == 'X') {
                ans++;
                for(int j = 0; j < 3 && i+j < n; j++) {
                    s[i+j] = 'O';
                }
            }
        }
        return ans;
    }
};