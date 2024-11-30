class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> cnt;
        int start = pairs[0][0], curr, to;
        vector<vector<int>> ans;
        stack<int> s;
        for(auto &i: pairs) {
            cnt[i[0]]++;
            cnt[i[1]]--;
            adj[i[1]].push_back(i[0]);
        }
        for(auto &[i, c]: cnt) {
            if(c < 0) start = i;
        }
        s.push(start);
        while(!s.empty()) {
            curr = s.top();
            if(!adj[curr].empty()) {
                s.push(adj[curr].back());
                adj[curr].pop_back();
            } else {
                s.pop();
                if(!s.empty()) ans.push_back({curr, s.top()});
            }
        }
        return ans;
    }
};