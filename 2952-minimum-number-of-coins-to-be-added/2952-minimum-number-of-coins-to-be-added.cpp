class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int ans = 0;
        int n = coins.size();
        sort(coins.begin(), coins.end());
        long long sm = 0;
        for(int i = 1, j = 0; i <= target; i++) {
            while(j < n && coins[j] <= sm + 1) {
                sm += coins[j];
                j++;
            }
            if(sm < i) {
                ans++;
                sm += i;
            }
        }
        return ans;
    }
};