class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int ans = numBottles, tmp;
        while(numBottles >= numExchange) {
            tmp = numBottles/numExchange;
            ans += tmp;
            numBottles = tmp + numBottles % numExchange;
        }
        return ans;
    }
};