class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> v(n, 0);
        int cnt = 0, ans = 0;
        for(int i = n-1, j = n-1; i >= 0; i--) {
            cnt += (v[fruits[i]]++ == 0);
            while(cnt > 2) cnt -= (--v[fruits[j--]] == 0);
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};