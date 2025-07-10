class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        startTime.push_back(eventTime);
        vector<int> v(2*n+1);
        v[0] = startTime[0];
        for(int i = 0; i < n; i++) {
            v[2*i+1] = endTime[i] - startTime[i];
            v[2*i+2] = startTime[i+1] - endTime[i];
        }
        int ans = 0, mx = 0;
        for(int i = 1; i <= 2*n; i += 2) {
            ans = max(ans, v[i-1] + v[i+1] + (mx >= v[i] ? v[i] : 0));
            mx = max(mx, v[i-1]);
        }
        mx = 0;
        for(int i = 2*n-1; i >= 1; i -= 2) {
            ans = max(ans, v[i-1] + v[i+1] + (mx >= v[i] ? v[i] : 0));
            mx = max(mx, v[i+1]);
        }
        return ans;
    }
};