class Solution {
public:
    long long f(string x, int &limit, string &s, unordered_map<string, long long> &memo) {
        if(memo.count(x)) return memo[x];
        if(x.size() < s.size()) return 0;
        if(x.size() == s.size()) return s <= x;
        int l = min(limit, x[0]-'0');
        long long &ret = memo[x];
        if(l == x[0]-'0') ret = f(string(x.size()-1, '9'), limit, s, memo) * l + f(x.substr(1, x.size()-1), limit, s, memo);
        else ret = f(string(x.size()-1, '9'), limit, s, memo) * (l+1);
        return ret;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        unordered_map<string, long long> memo;
        return f(to_string(finish), limit, s, memo) - f(to_string(start-1), limit, s, memo);
    }
};