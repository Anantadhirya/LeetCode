class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT_MAX, ans = INT_MAX, x;
        for(int &i: nums) {
            i <<= (i&1);
            mn = min(mn, i);
            pq.push(i);
        }
        ans = pq.top() - mn;
        while(pq.top() % 2 == 0) {
            x = pq.top();
            pq.pop();

            x >>= 1;
            mn = min(mn, x);
            pq.push(x);
            ans = min(ans, pq.top() - mn);
        }
        return ans;
    }
};