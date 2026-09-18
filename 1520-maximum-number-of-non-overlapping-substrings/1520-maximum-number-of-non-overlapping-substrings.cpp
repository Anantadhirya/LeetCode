class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<pair<int, int>> v(26, {-1, -1}), ans;
        vector<string> ret;
        vector<vector<int>> pref(26, vector<int>(n+1, 0));
        for(int i = 0, c; i < n; i++) {
            c = s[i]-'a';
            if(v[c].first == -1) v[c].first = i;
            v[c].second = i;
            for(int j = 0; j < 26; j++) {
                pref[j][i+1] = pref[j][i] + (c == j);
            }
        }
        for(int c = 0, done; c < 26; c++) {
            if(v[c].first == -1) continue;
            done = 0;
            while(!done) {
                done = 1;
                for(int j = 0; j < 26; j++) {
                    if(pref[j][v[c].second+1] - pref[j][v[c].first+1-1] > 0) {
                        if(v[j].first < v[c].first) v[c].first = v[j].first, done = 0;
                        if(v[j].second > v[c].second) v[c].second = v[j].second, done = 0;
                    }
                }
            }
        }
        sort(v.begin(), v.end());
        for(auto &[l, r]: v) {
            if(l == -1) continue;
            if(!ans.empty() && r <= ans.back().second) ans.pop_back();
            ans.push_back({l, r});
        }
        for(auto &[l, r]: ans) {
            ret.push_back("");
            for(int i = l; i <= r; i++) {
                ret.back() += s[i];
            }
        }
        return ret;
    }
};