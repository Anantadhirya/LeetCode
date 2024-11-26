class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> v(n, 0);
        int champion = -1;
        for(auto &i: edges) {
            v[i[1]] = 1;
        }
        for(int i = 0; i < n; i++) {
            if(!v[i]) {
                if(champion == -1) champion = i;
                else return -1;
            }
        }
        return champion;
    }
};