class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size(), ans = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        for(int i = 0, j = 0; i < n; i++) {
            while(j < m && trainers[j] < players[i]) j++;
            if(j == m) break;
            ans++;
            j++;
        }
        return ans;
    }
};