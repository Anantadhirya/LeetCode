class Solution {
public:
    bool issubset(vector<int> &a, vector<int> &b) {
        for(int i = a.size()-1, j = b.size()-1; i >= 0; i--) {
            while(j >= 0 && b[j] > a[i]) j--;
            if(j < 0 || a[i] != b[j]) return 0;
        }
        return 1;
    }
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        map<string, int> m;
        int cnt = 0;
        int n = favoriteCompanies.size();
        vector<vector<int>> v;
        vector<int> ans;
        for(auto &arr: favoriteCompanies) {
            v.push_back({});
            for(string &s: arr) {
                if(!m.count(s)) m[s] = cnt++;
                v.back().push_back(m[s]);
            }
            sort(v.back().begin(), v.back().end());
        }
        for(int i = 0; i < n; i++) {
            ans.push_back(i);
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                if(issubset(v[i], v[j])) {
                    ans.pop_back();
                    break;
                }
            }
        }
        return ans;
    }
};