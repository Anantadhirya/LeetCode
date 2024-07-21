class Solution {
public:
    vector<int> order(int &k, vector<vector<int>> &condition) {
        vector<vector<int>> adj(k);
        vector<int> cnt(k, 0);
        vector<int> ret(k), tmp;
        int curr, retcnt = 0;
        for(const auto &i: condition) {
            adj[i[0]-1].push_back(i[1]-1);
            cnt[i[1]-1]++;
        }
        for(int i = 0; i < k; i++) {
            if(cnt[i] == 0) tmp.push_back(i);
        }
        while(!tmp.empty()) {
            curr = tmp.back();
            tmp.pop_back();
            ret[curr] = retcnt++;
            for(const int &to: adj[curr]) {
                cnt[to]--;
                if(cnt[to] == 0) {
                    tmp.push_back(to);
                }
            }
        }
        if(retcnt == k) return ret;
        else return {};
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = order(k, rowConditions);
        vector<int> colOrder = order(k, colConditions);
        if(rowOrder.empty() || colOrder.empty()) return {};
        vector<vector<int>> ret(k, vector<int>(k, 0));
        for(int i = 0; i < k; i++) {
            ret[rowOrder[i]][colOrder[i]] = i+1;
        }
        return ret;
    }
};