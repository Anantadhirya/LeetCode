class Solution {
public:
    bool match(vector<pair<char, int>> &from, vector<pair<char, int>> &to, int &n) {
        for(int i = 0; i < n; i++) {
            if(from[i].first != to[i].first) return 0;
            if(from[i].second == to[i].second) continue;
            if(to[i].second > from[i].second && to[i].second >= 3) continue;
            return 0;
        }
        return 1;

    }
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char, int>> v, tmp;
        int ans = 0;
        for(char &c: s) {
            if(v.empty() || v.back().first != c) v.push_back({c, 1});
            else v.back().second++;
        }
        int n = v.size();
        for(string &i: words) {
            tmp.clear();
            for(char &c: i) {
                if(tmp.empty() || tmp.back().first != c) tmp.push_back({c, 1});
                else tmp.back().second++;
            }
            if(tmp.size() == n) {
                ans += match(tmp, v, n);
            }
        }
        return ans;
    }
};