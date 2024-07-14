class Solution {
public:
    map<string, int> solve(string formula) {
        int n = formula.size();
        map<string, int> ret;
        for(int i = 0; i < n; i++) {
            if(formula[i] == '(') {
                for(int j = i+1, t = 1; j < n; j++) {
                    if(formula[j] == '(') t++;
                    else if(formula[j] == ')') t--;
                    if(t == 0) {
                        for(int k = j+1; ; k++) {
                            if(k < n && '0' <= formula[k] && formula[k] <= '9') {
                                t = 10*t + (formula[k] - '0');
                            } else {
                                for(const auto &[s, i]: solve(formula.substr(0, i))) {
                                    ret[s] += i;
                                }
                                t = max(t, 1);
                                for(const auto &[s, i]: solve(formula.substr(i+1, j-i-1))) {
                                    ret[s] += t * i;
                                }
                                for(const auto &[s, i]: solve(formula.substr(k))) {
                                    ret[s] += i;
                                }
                                return ret;
                            }
                        }
                    }
                }
            }
        }
        string tmp;
        int t;
        for(int i = 0; i < n; ) {
            tmp = "";
            if('A' <= formula[i] && formula[i] <= 'Z') {
                tmp += formula[i];
                if(i+1 < n && 'a' <= formula[i+1] && formula[i+1] <= 'z') {
                    tmp += formula[++i];
                }
            }
            t = 0;
            i++;
            while(i < n && '0' <= formula[i] && formula[i] <= '9') {
                t = 10*t + (formula[i++] - '0');
            }
            t = max(t, 1);
            ret[tmp] += t;
        }
        return ret;
    }
    string countOfAtoms(string formula) {
        map<string, int> ans = solve(formula);
        string ret = "";
        for(auto &[s, i]: ans) {
            ret += s + (i > 1 ? to_string(i) : "");
        }
        return ret;
    }
};