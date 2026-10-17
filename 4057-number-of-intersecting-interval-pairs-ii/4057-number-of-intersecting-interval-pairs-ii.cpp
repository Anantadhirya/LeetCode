class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long ans = 0;
        priority_queue<int> pq;
        sort(intervals.begin(), intervals.end());
        for(auto &i: intervals) {
            while(!pq.empty() && -pq.top() < i[0]) pq.pop();
            ans += (long long)pq.size();
            pq.push(-i[1]);
        }
        return ans;
    }
};