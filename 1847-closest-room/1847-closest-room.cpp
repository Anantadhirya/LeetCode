class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = rooms.size();
        int k = queries.size();
        set<int> s;
        vector<pair<int,int>> ans(k, {INT_MAX, -1});
        vector<int> ret(k);
        for(int i = 0; i < n; i++) {
            rooms[i] = {rooms[i][1], rooms[i][0]};
        }
        for(int i = 0; i < k; i++) {
            queries[i] = {queries[i][1], queries[i][0], i};
        }
        sort(rooms.begin(), rooms.end());
        sort(queries.begin(), queries.end());
        for(int i = n-1, j = k-1; j >= 0; j--) {
            while(i >= 0 && rooms[i][0] >= queries[j][0]) {
                s.insert(rooms[i--][1]);
            }
            auto it = s.lower_bound(queries[j][1]);
            if(it != s.end()) {
                ans[queries[j][2]] = min(ans[queries[j][2]], {abs((*it) - queries[j][1]), *it});
            }
            if(it != s.begin()) {
                it--;
                ans[queries[j][2]] = min(ans[queries[j][2]], {abs((*it) - queries[j][1]), *it});
            }
        }
        for(int i = 0; i < k; i++) {
            ret[i] = ans[i].second;
        }
        return ret;
    }
};