class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        vector<long long> v(3*n, 0);
        priority_queue<int> pq;
        long long ans = LLONG_MAX, tmp = 0;
        for(int i = 0; i < n; i++) {
            v[n-1] += nums[i];
            pq.push(nums[i]);
        }
        for(int i = n; i < 2*n; i++) {
            v[i] = v[i-1] + nums[i];
            pq.push(nums[i]);
            v[i] -= pq.top();
            pq.pop();
        }
        while(!pq.empty()) pq.pop();
        for(int i = 3*n-1; i >= 2*n; i--) {
            tmp += nums[i];
            pq.push(-nums[i]);
        }
        ans = min(ans, v[2*n-1] - tmp);
        for(int i = 2*n-1; i >= n; i--) {
            tmp += nums[i];
            pq.push(-nums[i]);
            tmp -= -pq.top();
            pq.pop();
            ans = min(ans, v[i-1] - tmp);
        }
        return ans;
    }
};