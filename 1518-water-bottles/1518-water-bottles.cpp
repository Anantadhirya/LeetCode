class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, tmp;
        while(numBottles >= numExchange) {
            tmp = numBottles/numExchange;
            ans += tmp;
            numBottles = tmp + numBottles % numExchange;
        }
        return ans;
    }
};