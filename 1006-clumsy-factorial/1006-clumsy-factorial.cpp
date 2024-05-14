class Solution {
public:
    int clumsy(int n) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int ans = n, tmp;
        if(n-1 > 0) ans *= n-1;
        if(n-2 > 0) ans /= n-2;
        for(int i = n-3; i > 0; i -= 4) {
            ans += i;
            tmp = 0;
            if(i-1 > 0) tmp = i-1;
            if(i-2 > 0) tmp *= i-2;
            if(i-3 > 0) tmp /= i-3;
            ans -= tmp;
        }
        return ans;
    }
};