class Solution {
public:
    void solve(vector<char> &v, int &n, int &k, string &curr, vector<bool> &vis, string &s, string &ans) {
        for(int i = n-1; i >= 0; i--) {
            if(vis[i]) continue;
            vis[i] = 1;
            curr.push_back(v[i]);
            solve(v, n, k, curr, vis, s, ans);
            curr.pop_back();
            vis[i] = 0;
        }
        int idx = 0, sz = curr.size(), r = 0;
        if(sz < ans.size()) return;
        for(const char &c: s) {
            if(c == curr[idx]) idx++;
            if(idx == sz) r++, idx = 0;
        }
        if(r >= k) {
            if(sz > ans.size()) ans = curr;
            else ans = max(ans, curr);
        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> cnt(26, 0);
        vector<char> v;
        string curr;
        vector<bool> vis;
        int n;
        string ans;
        for(const char &c: s) {
            cnt[c-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < cnt[i]/k; j++) v.push_back('a'+i);
        }
        n = v.size();
        vis.assign(n, 0);
        solve(v, n, k, curr, vis, s, ans);
        return ans;
    }
};