class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> par(c+1);
        vector<bool> online(c+1, 1);
        vector<queue<int>> q(c+1);
        for(int i = 1; i <= c; i++) {
            par[i] = i;
        }
        for(auto i: connections) {
            i[0] = fp(i[0], par);
            i[1] = fp(i[1], par);
            par[i[0]] = i[1];
        }
        for(int i = 1; i <= c; i++) {
            q[fp(i, par)].push(i);
        }
        vector<int> ans;
        for(auto i: queries) {
            if(i[0] == 1) {
                if(online[i[1]]) ans.push_back(i[1]);
                else {
                    i[1] = fp(i[1], par);
                    while(!q[i[1]].empty() && !online[q[i[1]].front()]) q[i[1]].pop();
                    ans.push_back(q[i[1]].empty() ? -1 : q[i[1]].front());
                }
            } else if(i[0] == 2) {
                online[i[1]] = 0;
            }
        }
        return ans;
    }
};