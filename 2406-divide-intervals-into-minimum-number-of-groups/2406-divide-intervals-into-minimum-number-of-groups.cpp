class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        sort(intervals.begin(), intervals.end());
        priority_queue<int> pq;
        int ans = 0;
        for(const auto &i: intervals) {
            while(!pq.empty() && -pq.top() < i[0]) pq.pop();
            pq.push(-i[1]);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};