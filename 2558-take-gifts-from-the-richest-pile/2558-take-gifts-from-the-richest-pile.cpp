class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        long long ans = 0;
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while(k--) {
            pq.push(sqrt(1.0*pq.top()));
            pq.pop();
        }
        while(!pq.empty()) {
            ans += (long long)pq.top();
            pq.pop();
        }
        return ans;
    }
};