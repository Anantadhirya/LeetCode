class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> cnt;
        int ans = -1;
        for(const int &i: arr) cnt[i]++;
        for(const auto &[i, c]: cnt) if(c == i) ans = max(ans, i);
        return ans;
    }
};