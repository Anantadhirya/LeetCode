class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<vector<string>>> ans(n);
        string tmp;
        bool palindrome;
        for(int r = 0; r < n; r++) {
            tmp = "";
            for(int l = r; l >= 0; l--) {
                tmp += s[l];
                palindrome = 1;
                for(int i = 0; l+i <= r-i; i++) {
                    if(s[l+i] != s[r-i]) palindrome = 0;
                }
                if(palindrome) {
                    if(l == 0) {
                        ans[r].push_back({tmp});
                    } else {
                        for(const auto &i: ans[l-1]) {
                            ans[r].push_back(i);
                            ans[r].back().push_back(tmp);
                        }
                    }
                }
            }
        }
        return ans[n-1];
    }
};