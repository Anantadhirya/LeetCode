class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size() <= k) return s;
        string tmp = "";
        int n = s.size(), cur = 0;
        for(int i = 0; i < n; i++) {
            cur += (s[i]-'0');
            if(i%k == k-1 || i == n-1) {
                tmp += to_string(cur);
                cur = 0;
            }
        }
        return digitSum(tmp, k);
    }
};