class Solution {
public:
    vector<int> par;
    int fp(int i) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i]);
    }
    void join(int u, int v) {
        u = fp(u), v = fp(v);
        par[u] = v;
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int m = meetings.size();
        vector<int> ans;

        par.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }

        join(0, firstPerson);
        sort(meetings.begin(), meetings.end(), [&](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });
        for(int i = 0, j, u, v; i < m; ) {
            for(j = i; j < m && meetings[i][2] == meetings[j][2]; j++) {
                join(meetings[j][0], meetings[j][1]);
            }
            while(i < j) {
                u = meetings[i][0];
                v = meetings[i][1];
                if(fp(0) != fp(u)) {
                    par[u] = u;
                }
                if(fp(0) != fp(v)) {
                    par[v] = v;
                }
                i++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(fp(0) == fp(i)) ans.push_back(i);
        }
        return ans;
    }
};