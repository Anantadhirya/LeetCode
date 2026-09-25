class Solution {
public:
    set<string> solve(int l, int r, string &s) {
        if(r < l) return {""};
        if(l == r) return {string(1, s[l])};

        set<string> ans, tmp, tmpl;

        if(s[l] != '{') {
            tmp = solve(l+1, r, s);
            for(auto &i: tmp) {
                ans.insert(s[l] + i);
            }
            return ans;
        }

        for(int i = l, cnt = 0; i <= r; i++) {
            if(s[i] == '{') cnt++;
            else if(s[i] == '}') cnt--;
            if(cnt == 0) {
                for(int j = l+1, lst = l+1, cnt = 0; j <= i; j++) {
                    if(s[j] == '{') cnt++;
                    else if(s[j] == '}') cnt--;
                    
                    if(j == i || (s[j] == ',' && cnt == 0)) {
                        for(auto &x: solve(lst, j-1, s)) {
                            tmpl.insert(x);
                        }
                        lst = j+1;
                    }
                }
                tmp = solve(i+1, r, s);
                for(auto &e1: tmpl) {
                    for(auto &e2: tmp) {
                        ans.insert(e1 + e2);
                    }
                }
                break;
            }
        }
        return ans;
    }
    vector<string> braceExpansionII(string expression) {
        set<string> ans = solve(0, expression.size()-1, expression);
        return vector<string>(ans.begin(), ans.end());
    }
};