class Solution {
public:
    bool subfolder(string &a, string &b) {
        if(a.size() >= b.size()) return 0;
        if(b[a.size()] != '/') return 0;
        for(int i = a.size() - 1; i >= 0; i--) {
            if(a[i] != b[i]) return 0;
        }
        return 1;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        for(string &s: folder) {
            if(!ans.empty() && subfolder(ans.back(), s)) continue;
            ans.push_back(s);
        }
        return ans;
    }
};