const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

struct Trie {
    string s = "";
    unordered_map<string, Trie*> adj;
};

class Solution {
public:
    void dfs(Trie *curr, unordered_map<string, int> &cnt) {
        if(curr->adj.empty()) return;
        vector<string> v;
        for(const auto &[folder, node]: curr->adj) {
            dfs(node, cnt);
            v.push_back(folder + "(" + node->s + ")");
        }
        sort(v.begin(), v.end());
        for(const auto &s: v) {
            curr->s += s;
        }
        cnt[curr->s]++;
    }
    void dfs2(Trie *curr, unordered_map<string, int> &cnt, vector<string> &path, vector<vector<string>> &ans) {
        if(cnt[curr->s] > 1) return;
        if(!path.empty()) ans.push_back(path);
        for(const auto &[folder, node]: curr->adj) {
            path.push_back(folder);
            dfs2(node, cnt, path, ans);
            path.pop_back();
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie *root = new Trie();
        Trie *curr;
        for(const auto &path: paths) {
            curr = root;
            for(const auto &folder: path) {
                if(!curr->adj.count(folder)) {
                    curr->adj[folder] = new Trie();
                }
                curr = curr->adj[folder];
            }
        }
        unordered_map<string, int> cnt;
        dfs(root, cnt);
        vector<string> path;
        vector<vector<string>> ans;
        dfs2(root, cnt, path, ans);
        return ans;
    }
};