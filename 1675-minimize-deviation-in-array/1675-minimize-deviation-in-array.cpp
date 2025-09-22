class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<pair<int, int>> pq;
        int mx = 0, x;
        int ans;
        for(const int &i: nums) {
            x = i;
            while(~x&1) x >>= 1;
            mx = max(mx, x);
            pq.push({-x, (i&1 ? 2*i : i)});
        }
        while(-pq.top().first <= (min(mx,pq.top().second)>>1)) {
            x = -pq.top().first;
            while(x <= (min(mx,pq.top().second)>>1)) x <<= 1;
            pq.push({-x, pq.top().second});
            pq.pop(); 
        }
        ans = mx + pq.top().first;
        while(1) {
            x = -pq.top().first;
            if(x <= (pq.top().second>>1)) {
                x <<= 1;
                mx = max(mx, x);
                pq.push({-x, pq.top().second});
                pq.pop();
            } else break;
            while(-pq.top().first <= (min(mx, pq.top().second)>>1)) {
                pq.push({2*pq.top().first, pq.top().second});
                pq.pop();
            }
            ans = min(ans, mx + pq.top().first);
        }
        return ans;
    }
};