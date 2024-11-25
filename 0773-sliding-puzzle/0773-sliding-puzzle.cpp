class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int slidingPuzzle(vector<vector<int>>& board) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        map<vector<vector<int>>, int> dist;
        queue<vector<vector<int>>> q;
        vector<vector<int>> v = {{1, 2, 3}, {4, 5, 0}}, tmp;
        dist[v] = 0;
        q.push(v);
        while(!q.empty()) {
            v = tmp = q.front();
            q.pop();
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 3; j++) {
                    if(v[i][j] == 0) {
                        for(int d = 0, ii, jj; d < 4; d++) {
                            ii = i + dx[d];
                            jj = j + dy[d];
                            if(0 <= ii && ii < 2 && 0 <= jj && jj < 3) {
                                swap(tmp[i][j], tmp[ii][jj]);
                                if(!dist.count(tmp)) {
                                    dist[tmp] = dist[v] + 1;
                                    q.push(tmp);
                                }
                                swap(tmp[i][j], tmp[ii][jj]);
                            }
                        }
                    }
                }
            }
        }
        return dist.count(board) ? dist[board] : -1;
    }
};