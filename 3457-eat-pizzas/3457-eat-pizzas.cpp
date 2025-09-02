class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long ans = 0;
        int n = pizzas.size();
        int idx = n-1;
        int k = n/4;
        int odd = (k+1)/2, even = k/2;
        sort(pizzas.begin(), pizzas.end());
        for(int i = 0; i < odd; i++) {
            ans += pizzas[idx--];
        }
        for(int i = 0; i < even; i++) {
            ans += pizzas[--idx];
            idx--;
        }
        return ans;
    }
};