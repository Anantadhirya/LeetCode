class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int a = 1, b = 1;
        int nn = hBars.size(), mm = vBars.size();
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        for(int i = 1, t = 1; i < nn; i++) {
            if(hBars[i] == n+2) continue;
            if(hBars[i-1] != 1 && hBars[i-1] + 1 == hBars[i]) t++;
            else t = 1;
            a = max(a, t);
        }
        for(int i = 1, t = 1; i < mm; i++) {
            if(vBars[i] == m+2) continue;
            if(vBars[i-1] != 1 && vBars[i-1] + 1 == vBars[i]) t++;
            else t = 1;
            b = max(b, t);
        }
        a = min(a, b)+1;
        return a*a;
    }
};