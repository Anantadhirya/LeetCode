class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        long long rem = 0, req;
        sort(batteries.begin(), batteries.end());
        for(int i = 0; i < m-n; i++) {
            rem += batteries[i];
        }
        for(int i = 0; i+1 < n; i++) {
            req = (long long)(i+1) * (batteries[m-n+i+1] - batteries[m-n+i]);
            if(rem >= req) rem -= req;
            else {
                return batteries[m-n+i] + rem/(i+1);
            }
        }
        return batteries[m-1] + rem/n;
    }
};