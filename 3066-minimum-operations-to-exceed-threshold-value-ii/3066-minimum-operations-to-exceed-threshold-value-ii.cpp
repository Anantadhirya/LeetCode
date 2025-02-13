const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return NULL; }();

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        int ans = 0;
        for(const int &i: nums) {
            pq.push(-i);
        }
        for(long long i, j; -pq.top() < k; ) {
            i = -pq.top();
            pq.pop();
            j = -pq.top();
            pq.pop();
            pq.push(-(2*i + j));
            ans++;
        }
        return ans;
    }
};