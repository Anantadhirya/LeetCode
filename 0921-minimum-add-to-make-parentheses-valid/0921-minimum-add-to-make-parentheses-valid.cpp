class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, ans = 0;
        for(const auto &i: s) {
            cnt += (i == '(' ? 1 : -1);
            if(cnt < 0) ans++, cnt = 0;
        }
        return ans + cnt;
    }
};