class Solution {
public:
    string generateString(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        string ans(n+m-1, 'a');
        vector<bool> fixed(n+m-1, 0);
        bool match;
        for(int i = 0; i < n; i++) {
            if(s1[i] == 'F') continue;
            for(int j = 0; j < m; j++) {
                if(fixed[i+j] && ans[i+j] != s2[j]) return "";
                ans[i+j] = s2[j];
                fixed[i+j] = 1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(s1[i] == 'T') continue;
            match = 1;
            for(int j = 0; j < m; j++) {
                if(ans[i+j] != s2[j]) {
                    match = 0;
                    break;
                }
            }
            if(match) {
                for(int j = m-1; j >= 0; j--) {
                    if(!fixed[i+j]) {
                        ans[i+j]++;
                        match = 0;
                        break;
                    }
                }
                if(match) return "";
            }
        }
        return ans;
    }
};