class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size(), t = 0;
        string ans(n, ' ');
        
        for(int i = 0; i < n; i++) {
            if(ans[i] != ' ') continue;
            ans[i] = 'a' + t;
            if(t++ >= 26) return ""; 
            for(int j = 0; j < n; j++) if(lcp[i][j]) ans[j] = ans[i];
        }
        // cout << ans << "\n";
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                t = (ans[i] == ans[j] ? 1 + (i+1 < n && j+1 < n ? lcp[i+1][j+1] : 0) : 0);
                if(lcp[i][j] != t) return "";
            }
        }
        return ans;
    }
};