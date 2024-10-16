class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "", tmp = "  ";
        char add = ' ';
        int mx;
        while(a > 0 || b > 0 || c > 0) {
            mx = max(a, max(b, c));
            if(a == mx) {
                if(tmp != "aa") {
                    add = 'a';
                } else {
                    if(b == 0 && c == 0) break;
                    add = (b >= c ? 'b' : 'c');
                }
            } else if(b == mx) {
                if(tmp != "bb") {
                    add = 'b';
                } else {
                    if(a == 0 && c == 0) break;
                    add = (a >= c ? 'a' : 'c');
                }
            } else if(c == mx) {
                if(tmp != "cc") {
                    add = 'c';
                } else {
                    if(a == 0 && b == 0) break;
                    add = (a >= b ? 'a' : 'b');
                }
            }
            ans.push_back(add);
            tmp[0] = tmp[1];
            tmp[1] = add;
            if(add == 'a') a--;
            else if(add == 'b') b--;
            else if(add == 'c') c--;
        }
        return ans;
    }
};