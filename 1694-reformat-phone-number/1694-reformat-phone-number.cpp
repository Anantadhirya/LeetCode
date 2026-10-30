class Solution {
public:
    string reformatNumber(string number) {
        string s;
        for(auto &c: number) {
            if('0' <= c && c <= '9') s.push_back(c);
        }
        int n = s.size();
        string ans;
        for(int i = 0; i < n; ) {
            if(n-i > 4) {
                ans += s.substr(i, 3) + "-";
                i += 3;
            } else {
                if(n-i == 4) ans += s.substr(i, 2) + "-" + s.substr(i+2, 2);
                else if(n-i == 3) ans += s.substr(i, 3);
                else if(n-i == 2) ans += s.substr(i, 2);
                break;
            }
        }
        return ans;
    }
};