class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int lg = log2(n) + 3;
        vector<pair<int, int>> v(n);
        vector<int> pos(n), ans;
        vector<vector<int>> nxt(n, vector<int>(lg, -1));
        int x, a, b;
        for(int i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            pos[v[i].second] = i;
        }
        for(int i = n-1, j = n-1; i >= 0; i--) {
            while(v[j].first - v[i].first > maxDiff) j--;
            nxt[i][0] = j;
            for(int k = 1; k < lg; k++) {
                nxt[i][k] = nxt[nxt[i][k-1]][k-1];
            }
        }
        for(auto &i: queries) {
            a = pos[i[0]];
            b = pos[i[1]];
            if(a > b) swap(a, b);
            if(a == b) {
                ans.push_back(0);
                continue;
            }
            x = 0;
            for(int k = lg-1; k >= 0; k--) {
                if(nxt[a][k] < b) {
                    x += (1<<k);
                    a = nxt[a][k];
                }
            }
            if(nxt[a][0] >= b) ans.push_back(x+1);
            else ans.push_back(-1);
        }
        return ans;
    }
};