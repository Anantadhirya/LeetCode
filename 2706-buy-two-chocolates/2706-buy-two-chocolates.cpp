class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int a = prices[0], b = prices[1], n = prices.size();
        if(a < b) swap(a, b);
        for(int i = 2; i < n; i++) {
            if(prices[i] < a) {
                a = prices[i];
                if(a < b) swap(a, b);
            } else if(prices[i] < b) b = prices[i];
        }
        cout << a << " " << b << "\n";
        return a + b <= money ? money - a - b : money;
    }
};