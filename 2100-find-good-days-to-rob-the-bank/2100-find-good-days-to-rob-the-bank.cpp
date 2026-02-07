class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        if(n <= 2*time) return {};
        int cnt = 0;
        vector<int> ans;
        for(int i = 0; i < time; i++) {
            cnt += (security[i] >= security[i+1]);
        }
        for(int i = time; i < 2*time; i++) {
            cnt += (security[i] <= security[i+1]);
        }
        for(int i = time; i+time < n; i++) {
            if(cnt == 2*time) ans.push_back(i);
            if(i+time == n-1) break;
            cnt -= (security[i-time] >= security[i-time+1]);
            cnt += (security[i] >= security[i+1]);
            cnt -= (security[i] <= security[i+1]);
            cnt += (security[i+time] <= security[i+time+1]);
        }
        return ans;
    }
};