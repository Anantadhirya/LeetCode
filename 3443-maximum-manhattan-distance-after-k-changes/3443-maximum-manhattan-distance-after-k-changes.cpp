const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        for(int d = 0, i, j; d < 4; d++) {
            i = j = 0;
            for(char &c: s) {
                if(c == 'N') i++, c = 'E';
                else if(c == 'S') i--, j++, c = 'W';
                else if(c == 'E') i++, c = 'S';
                else if(c == 'W') i--, j++, c = 'N';
                ans = max(ans, i + 2*min(j, k));
            }
        }
        return ans;
    }
};