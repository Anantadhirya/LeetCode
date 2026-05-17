class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(start);
        for(int cur; !q.empty(); ) {
            cur = q.front();
            q.pop();
            if(vis[cur]) continue;
            vis[cur] = 1;
            if(cur-arr[cur] >= 0) q.push(cur-arr[cur]);
            if(cur+arr[cur] < n) q.push(cur+arr[cur]);
        }
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0 && vis[i]) return 1;
        }
        return 0;
    }
};