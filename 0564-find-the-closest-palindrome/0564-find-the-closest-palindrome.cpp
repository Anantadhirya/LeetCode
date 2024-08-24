class Solution {
public:
    string nearestPalindromic(string s) {
        int n = s.size();
        long long x = stoll(s);
        vector<long long> v;
        int l, r;
        pair<long long, long long> ans = {LLONG_MAX, 0};
        for(l = 0, r = n-1; l <= r; l++, r--) {
            s[r] = s[l];
        }
        v.push_back(stoll(s));
        l = (n-1)/2, r = n/2;
        cout << l << " " << r << "\n";
        if(s[l] != '0') {
            s[l] = s[r] -= 1;
            v.push_back(stoll(s));
            s[l] = s[r] += 1;
        } else if(l-1 >= 0 && s[l-1] != '0') {
            s[l] = s[r] = '9';
            s[l-1] = s[r+1] -= 1;
            v.push_back(stoll(s));
            s[l-1] = s[r+1] += 1;
            s[l] = s[r] = '0';
        }
        if(s[l] != '9') {
            s[l] = s[r] += 1;
            v.push_back(stoll(s));
            s[l] = s[r] -= 1;
        }
        if(n != 1) v.push_back(stoll(string(n-1, '9')));
        v.push_back(stoll("1" + string(n-1, '0') + "1"));
        for(const long long &i: v) {
            if(i == x) continue;
            ans = min(ans, {abs(i-x), i});
        }
        return to_string(ans.second);
    }
};