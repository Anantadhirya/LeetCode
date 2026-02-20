class Solution {
public:
    string solve(string &s, int l, int r) {
        if(l+1 == r) return s.substr(l, 2);
        vector<string> v;
        string ret = "";
        for(int i = l, c = 0, lst = l; i <= r; i++) {
            if(s[i] == '1') c++;
            else c--;

            if(c == 0) {
                if(lst == l && i == r) v.push_back(s[lst] + solve(s, lst+1, i-1) + s[i]);
                else v.push_back(solve(s, lst, i));
                lst = i+1;
            }
        }
        sort(v.rbegin(), v.rend());
        for(auto i: v) ret += i;
        return ret;
    }
    string makeLargestSpecial(string s) {
        return solve(s, 0, s.size()-1);
    }
};