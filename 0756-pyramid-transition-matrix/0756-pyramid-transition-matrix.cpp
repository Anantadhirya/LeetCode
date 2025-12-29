class Solution {
public:
    vector<string> adj(string cur, vector<vector<vector<char>>> &v) {
        vector<string> ret(1, ""), tmp;
        int n = cur.size();
        for(int i = 0; i+1 < n; i++) {
            tmp.clear();
            for(string s: ret) {
                for(char x: v[cur[i]-'A'][cur[i+1]-'A']) {
                    tmp.push_back(s + x);
                }
            }
            swap(ret, tmp);
        }
        return ret;
    }
    bool dfs(string cur, unordered_set<string> &vis, vector<vector<vector<char>>> &v) {
        if(cur.size() == 1) return 1;
        if(vis.count(cur)) return 0;
        vis.insert(cur);
        for(auto to: adj(cur, v)) {
            if(dfs(to, vis, v)) return 1;
        }
        return 0;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<vector<char>>> v(26, vector<vector<char>>(26));
        unordered_set<string> vis;
        int n = bottom.size();
        for(auto s: allowed) {
            v[s[0]-'A'][s[1]-'A'].push_back(s[2]);
        }
        return dfs(bottom, vis, v);
    }
};