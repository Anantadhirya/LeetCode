class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<int> owned(n, 0);
        vector<bool> vis(n, 0);
        queue<int> q;
        int ans = 0, curr;
        for(const auto &i: initialBoxes) {
            owned[i] = 1;
            if(status[i] == 1) q.push(i);
        }
        while(!q.empty()) {
            curr = q.front();
            q.pop();
            if(vis[curr]) continue;
            vis[curr] = 1;
            ans += candies[curr];
            for(int &to: containedBoxes[curr]) {
                owned[to] = 1;
                if(status[to] == 1) q.push(to);
            }
            for(int &to: keys[curr]) {
                status[to] = 1;
                if(owned[to] == 1) q.push(to);
            }
        }
        return ans;
    }
};