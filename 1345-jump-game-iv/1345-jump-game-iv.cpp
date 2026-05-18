class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int, vector<int>> pos;
        for(int i = 0; i < arr.size(); i++) {
            pos[arr[i]].push_back(i);
        }
        int inf = INT_MAX;
        vector<int> dist(arr.size(), inf);
        queue<int> q;
        int curr;
        dist[0] = 0;
        q.push(0);
        while(!q.empty()) {
            curr = q.front();
            if(curr == arr.size()-1) return dist[curr];
            q.pop();
            if(curr+1 < arr.size() && dist[curr+1] == inf) {
                dist[curr+1] = dist[curr] + 1;
                q.push(curr+1);
            }
            if(curr-1 >= 0 && dist[curr-1] == inf) {
                dist[curr-1] = dist[curr] + 1;
                q.push(curr-1);
            }
            for(auto i: pos[arr[curr]]) {
                if(dist[i] == inf) {
                    dist[i] = dist[curr] + 1;
                    q.push(i);
                }
            }
            pos[arr[curr]].clear();
        }
        return dist[arr.size()-1];
    }
};