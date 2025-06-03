const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<int> owned(n, 0);
        queue<int> q;
        int ans = 0, curr;
        for(const auto &i: initialBoxes) {
            if(status[i] == 1) q.push(i);
            else owned[i] = 1;
        }
        while(!q.empty()) {
            curr = q.front();
            q.pop();
            ans += candies[curr];
            for(int &to: containedBoxes[curr]) {
                owned[to] = 1;
                if(status[to] == 1) q.push(to), owned[to] = 0;
            }
            for(int &to: keys[curr]) {
                status[to] = 1;
                if(owned[to] == 1) q.push(to), owned[to] = 0;
            }
        }
        return ans;
    }
};