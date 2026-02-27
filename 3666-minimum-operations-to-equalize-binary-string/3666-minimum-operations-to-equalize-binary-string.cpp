class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size(), cnt = 0, cur;
        int mnz, mxz, l, r;
        set<int> st[2];
        vector<int> dist(n+1, 0);
        queue<int> q;
        for(auto &c: s) cnt += (c == '0');
        for(int i = 0; i <= n; i++) {
            st[i&1].insert(i);
        }
        q.push(cnt);
        st[cnt&1].erase(cnt);
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            if(cur == 0) return dist[cur];
            mxz = min(k, cur);
            mnz = k - min(k, n-cur);
            l = cur + k - 2*mxz;
            r = cur + k - 2*mnz;
            auto &tmp = st[l&1];
            for(auto it = tmp.lower_bound(l); it != tmp.end() && *it <= r; ) {
                dist[*it] = dist[cur] + 1;
                q.push(*it);
                it = tmp.erase(it);
            }
        }
        return -1;
    }
};