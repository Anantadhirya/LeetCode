class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0, empty = 0;
        while(numBottles > 0) {
            ans += numBottles;
            empty += numBottles;
            numBottles = 0;
            while(empty >= numExchange) {
                empty -= numExchange;
                numExchange++;
                numBottles++;
            }
        }
        return ans;
    }
};