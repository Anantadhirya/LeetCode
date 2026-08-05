class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> sus(n, 0);
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> ans;
        q.push(k);
        for(auto &i: invocations) {
            adj[i[0]].push_back(i[1]);
        }
        for(int cur; !q.empty(); ) {
            cur = q.front();
            q.pop();
            sus[cur] = 1;
            for(int &to: adj[cur]) {
                if(sus[to]) continue;
                q.push(to);
            }
        }
        for(auto &i: invocations) {
            if(!sus[i[0]] && sus[i[1]]) {
                for(int i = 0; i < n; i++) ans.push_back(i);
                return ans;
            }
        }
        for(int i = 0; i < n; i++) {
            if(!sus[i]) ans.push_back(i);
        }
        return ans;
    }
};