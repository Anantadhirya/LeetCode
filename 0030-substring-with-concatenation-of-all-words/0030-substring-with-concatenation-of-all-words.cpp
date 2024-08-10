class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = s.size();
        int m = words[0].size();
        vector<string> v;
        map<string, int> cnt, tmp;
        for(const auto word: words) {
            cnt[word]++;
        }
        vector<int> ans;
        for(int j = 0; j < m; j++) {
            v.clear();
            for(int i = j; i < n; i++) {
                if(i % m == j) v.push_back("");
                v.back() += s[i];
            }
            if(!v.empty() && v.back().size() != m) v.pop_back();
            tmp.clear();
            // cout << j << ":\n";
            // for(int i = 0; i < v.size(); i++) {
            //     cout << v[i] << " ";
            // }
            // cout << "\n";
            for(int l = v.size()-1, r = v.size()-1; l >= 0; l--) {
                tmp[v[l]]++;
                while(tmp[v[l]] > cnt[v[l]]) {
                    tmp[v[r--]]--;
                }
                if(r-l+1 == words.size()) {
                    ans.push_back(j + m*l);
                }
            }
        }
        return ans;
    }
};