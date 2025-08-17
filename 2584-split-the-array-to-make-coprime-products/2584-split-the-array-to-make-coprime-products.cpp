class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> fac(mx+1, 0), l(mx+1, 0), r(mx+1, 0);
        int n = nums.size(), cnt = 0;
        for(int i = 2; i <= mx; i++) {
            if(fac[i] != 0) continue;
            fac[i] = i;
            if(i > mx/i) continue;
            for(int j = i*i; j <= mx; j += i) {
                if(fac[j] == 0) fac[j] = i;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = nums[i], k; j > 1; ) {
                k = fac[j];
                r[k]++;
                while(j % k == 0) j /= k;
            }
        }
        for(int i = 0; i < n-1; i++) {
            for(int j = nums[i], k; j > 1; ) {
                k = fac[j];
                cnt -= (l[k] && r[k]);
                l[k]++;
                r[k]--;
                cnt += (l[k] && r[k]);
                while(j % k == 0) j /= k;
            }
            if(cnt == 0) return i;
        }
        return -1;
    }
};