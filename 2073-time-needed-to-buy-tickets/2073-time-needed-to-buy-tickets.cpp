class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, n = tickets.size();
        for(int i = 0; i < n; i++) {
            ans += min(tickets[i], tickets[k] - (i > k));
        }
        return ans;
    }
};