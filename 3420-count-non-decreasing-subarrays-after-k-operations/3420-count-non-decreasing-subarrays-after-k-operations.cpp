class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>> dq;
        pair<int, int> cur;
        long long ans = 0, tmp = 0;
        vector<long long> suff(n+1, 0);
        for(int i = n-1; i >= 0; i--) suff[i] = suff[i+1] + nums[i];
        for(int i = n-1, l, r; i >= 0; i--) {
            cur = {i, i};
            while(!dq.empty() && nums[i] >= nums[dq.front().first]) {
                l = dq.front().first;
                r = dq.front().second;
                cur.second = r;
                tmp -= (long long)nums[l] * (r-l+1) - (suff[l] - suff[r+1]);
                dq.pop_front();
            }
            l = cur.first;
            r = cur.second;
            tmp += (long long)nums[l] * (r-l+1) - (suff[l] - suff[r+1]);
            dq.push_front(cur);

            while(tmp > k) {
                tmp -= (long long)nums[dq.back().first] - nums[dq.back().second];
                dq.back().second--;
                if(dq.back().second < dq.back().first) dq.pop_back();
            }

            ans += (long long)(dq.back().second-i+1);
        }
        return ans;
    }
};