class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        for(auto &i: tasks) {
            i = {i[1]-i[0], i[0], i[1]};
        }
        sort(tasks.begin(), tasks.end());
        int ans = 0;
        for(auto &i: tasks) {
            ans = max(ans + i[1], i[2]);
        }
        return ans;
    }
};