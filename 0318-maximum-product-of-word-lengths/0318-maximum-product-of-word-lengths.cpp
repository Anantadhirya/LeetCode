class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<bitset<26>> v(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(char &c: words[i]) v[i][c-'a'] = 1;
            for(int j = 0; j < i; j++) {
                if((v[i] & v[j]).count() == 0) ans = max(ans, (int)words[i].size() * (int)words[j].size());
            }
        }
        return ans;
    }
};