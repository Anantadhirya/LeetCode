class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        long long a = 0, b = 0;
        auto check = [&](long long x, long long y, int start) -> bool {
            long long cur = 0;
            if(start >= n) return 0;
            for(int i = start; i < n; ) {
                y = x+y;
                x = y-x;
                cur = 0;
                if(y == 0) {
                    if(num[i] == '0') {
                        i++;
                        continue;
                    } else return 0;
                }
                while(cur < y && i < n) {
                    if(cur == 0 && num[i] == '0') return 0;
                    cur = cur*10 + (num[i++]-'0');
                }
                if(cur > y) return 0;
            }
            return cur == y;
        };
        for(int i = 0; i <= n/2; i++) {
            a = a*10 + (num[i]-'0');
            b = 0;
            for(int j = i+1; j <= min(n-1, i+1+n/2); j++) {
                b = b*10 + (num[j]-'0');
                // cout << a << " " << b << "\n";
                if(check(a, b, j+1)) return 1;
                if(b == 0) break;
            }
            if(a == 0) break;
        }
        return 0;
    }
};