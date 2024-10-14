class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(const auto &i: nums) {
            pq.push(i);
        }
        long long ans = 0, curr;
        while(k--) {
            curr = pq.top();
            pq.pop();
            ans += curr;
            pq.push((curr+2)/3);
        }
        return ans;
    }
};