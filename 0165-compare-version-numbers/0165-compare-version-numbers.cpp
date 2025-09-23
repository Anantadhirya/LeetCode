class Solution {
public:
    vector<int> split(string &s) {
        vector<string> tmp(1, "");
        for(const char &c: s) {
            if(c == '.') tmp.push_back("");
            else tmp.back() += c;
        }
        vector<int> ret;
        for(const string &i: tmp) {
            ret.push_back(stoi(i));
        }
        return ret;
    }
    int compareVersion(string version1, string version2) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> v1 = split(version1), v2 = split(version2);
        int n1 = v1.size(), n2 = v2.size(), n = max(n1, n2);
        for(int i = 0, a, b; i < n; i++) {
            a = (i < n1 ? v1[i] : 0);
            b = (i < n2 ? v2[i] : 0);
            if(a != b) {
                return a > b ? 1 : -1;
            }
        }
        return 0;
    }
};