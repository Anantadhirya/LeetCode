class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> par(26);
        for(int i = 0; i < 26; i++) par[i] = i;
        int n = s1.size();
        for(int i = 0, u, v; i < n; i++) {
            u = fp(s1[i]-'a', par);
            v = fp(s2[i]-'a', par);
            if(u < v) swap(u, v);
            par[u] = v;
        }
        for(char &c: baseStr) {
            c = 'a' + fp(c-'a', par);
        }
        return baseStr;
    }
};