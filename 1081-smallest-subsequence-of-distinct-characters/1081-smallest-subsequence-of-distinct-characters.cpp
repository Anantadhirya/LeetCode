class Solution {
public:
    string smallestSubsequence(string s) {
        bitset<26> b;
        int n = s.size();
        vector<int> lst(26, 0);
        for(int i = 0; i < n; i++) {
            lst[s[i]-'a'] = i;
        }
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(b[s[i]-'a']) continue;
            while(!ans.empty() && ans.back() > s[i] && i < lst[ans.back()-'a']) b[ans.back()-'a'] = 0, ans.pop_back();
            ans += s[i];
            b[s[i]-'a'] = 1;
        }
        return ans;
    }
};