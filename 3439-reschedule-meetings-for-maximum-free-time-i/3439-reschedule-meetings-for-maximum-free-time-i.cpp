class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        startTime.push_back(eventTime);
        int tmp = 0;
        for(int i = 0; i < k; i++) {
            tmp += endTime[i] - startTime[i]; 
        }
        int ans = startTime[k] - tmp;
        for(int i = 0; i+k < n; i++) {
            tmp += (endTime[i+k] - startTime[i+k]) - (endTime[i] - startTime[i]);
            ans = max(ans, startTime[i+k+1] - endTime[i] - tmp);
        }
        return ans;
    }
};