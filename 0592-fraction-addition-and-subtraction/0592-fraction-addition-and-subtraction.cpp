class Solution {
public:
    long long gcd(long long a, long long b) {
        if(a == 0) return b;
        return gcd(b%a, a);
    }
    string fractionAddition(string expression) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        string tmp = "";
        vector<pair<long long, long long>> v;
        expression.push_back('+');
        for(const auto &c: expression) {
            if(c == '+' || c == '-') {
                if(!tmp.empty()) {
                    for(int i = tmp.size()-1; i >= 0; i--) {
                        if(tmp[i] == '/') {
                            v.push_back({stoi(tmp.substr(0, i)), stoi(tmp.substr(i+1))});
                            tmp.clear();
                            break;
                        }
                    }
                }
            }
            tmp += c;
        }
        pair<long long, long long> ans = {0, 1};
        long long g;
        for(auto &[a, b]: v) {
            g = gcd(ans.second, b);
            ans.first *= b / g;
            ans.first += ans.second / g * a;
            ans.second *= b / g;
            g = gcd(abs(ans.first), ans.second);
            ans.first /= g;
            ans.second /= g;
        }
        return to_string(ans.first) + "/" + to_string(ans.second);
    }
};