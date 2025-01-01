class Solution {
public:
    bool vowel(char &c) {
        return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> suff(n+1, 0);
        vector<int> ans(queries.size());
        for(int i = n-1; i >= 0; i--) {
            suff[i] = suff[i+1] + (vowel(words[i][0]) && vowel(words[i].back()));
        }
        for(int i = queries.size()-1; i >= 0; i--) {
            ans[i] = suff[queries[i][0]] - suff[queries[i][1]+1];
        }
        return ans;
    }
};