class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        int n = classes.size();
        double ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (double)classes[i][0]/classes[i][1];
            pq.push({(double)(classes[i][0] + 1)/(classes[i][1] + 1) - (double)classes[i][0]/classes[i][1], i});
        }
        while(extraStudents--) {
            ans += pq.top().first;
            n = pq.top().second;
            pq.pop();
            classes[n][0]++;
            classes[n][1]++;
            pq.push({(double)(classes[n][0] + 1)/(classes[n][1] + 1) - (double)classes[n][0]/classes[n][1], n});
        }
        return ans / classes.size();
    }
};