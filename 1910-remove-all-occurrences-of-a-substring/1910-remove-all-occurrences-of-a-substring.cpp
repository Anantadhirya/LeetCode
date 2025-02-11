class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = part.size(), m;
        bool del;
        for(const auto &c: s) {
            ans += c;
            while(ans.size() >= n) {
                del = 1;
                m = ans.size();
                for(int i = 0; i < n; i++) {
                    if(ans[m-n+i] != part[i]) {
                        del = 0;
                        break;
                    }
                }
                if(del) {
                    for(int i = 0; i < n; i++) ans.pop_back();
                } else break;
            }
        }
        return ans;
    }
};