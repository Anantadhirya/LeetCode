class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size();
        long long cnt = 0, med1, med2;
        int mode = 0;
        vector<double> ans = {n+1.0, -1, 0, 0, 0};
        for(int i = 0; i < n; i++) {
            cnt += count[i];
            if(count[i]) {
                ans[0] = min(ans[0], (double)i);
                ans[1] = max(ans[1], (double)i);
                ans[2] += (double)count[i] * i;
            }
            if(count[i] > count[mode]) mode = i;
        }
        ans[2] /= cnt;
        med1 = floor((cnt+1)/2.0), med2 = ceil((cnt+1)/2.0);
        for(int i = 0; med1 > 0 || med2 > 0; i++) {
            if(med1 > 0 && med1 - count[i] <= 0) ans[3] += i;
            if(med2 > 0 && med2 - count[i] <= 0) ans[3] += i;
            med1 -= count[i];
            med2 -= count[i];
        }
        ans[3] /= 2;
        ans[4] = mode;
        return ans;
    }
};