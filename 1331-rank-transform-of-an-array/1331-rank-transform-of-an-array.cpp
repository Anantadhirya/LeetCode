class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        map<int, int> rank;
        for(const auto &i: arr) {
            rank[i] = 0;
        }
        int cnt = 0;
        for(const auto &[i, _]: rank) {
            rank[i] = ++cnt;
        }
        for(auto &i: arr) {
            i = rank[i];
        }
        return arr;
    }
};