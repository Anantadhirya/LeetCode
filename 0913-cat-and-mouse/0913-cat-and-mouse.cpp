class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(3, 0))); // mouse, cat, turn
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(3, 0)));
        queue<array<int, 3>> q;

        auto add = [&](int mouse, int cat, int turn, int x) -> void {
            dp[mouse][cat][turn] = x;
            q.push({mouse, cat, turn});
        };

        for(int i = 0; i < n; i++) {
            for(int t = 1; t <= 2; t++) {
                add(0, i, t, 1);
                if(i > 0) add(i, i, t, 2);
            }
        }
        for(int mouse = 0; mouse < n; mouse++) {
            for(int cat = 0; cat < n; cat++) {
                degree[mouse][cat][1] = graph[mouse].size();
                degree[mouse][cat][2] = graph[cat].size();
                for(int to: graph[cat]) if(to == 0) degree[mouse][cat][2]--;
            }
        }

        while(!q.empty()) {
            auto [mouse, cat, turn] = q.front();
            q.pop();
            if(turn == 1) { // now is mouse's turn, prev turn is cat's turn
                for(int &cat1: graph[cat]) {
                    if(cat1 == 0) continue;
                    if(dp[mouse][cat1][2] != 0) continue;
                    if(dp[mouse][cat][turn] == 2) add(mouse, cat1, 2, 2);
                    else if(--degree[mouse][cat1][2] == 0) add(mouse, cat1, 2, 1);
                }
            } else {
                for(int &mouse1: graph[mouse]) {
                    if(dp[mouse1][cat][1] != 0) continue;
                    if(dp[mouse][cat][turn] == 1) add(mouse1, cat, 1, 1);
                    else if(--degree[mouse1][cat][1] == 0) add(mouse1, cat, 1, 2);
                }
            }
        }

        return dp[1][2][1];
    }
};