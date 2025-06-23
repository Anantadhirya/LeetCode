class Solution {
public:
    bool check(long long x, int k) {
        vector<char> v;
        while(x > 0) {
            v.push_back(x % k);
            x /= k;
        }
        int n = v.size();
        for(int i = 0; i < n-1-i; i++) {
            if(v[i] != v[n-1-i]) return 0;
        }
        return 1;
    }
    long long kMirror(int k, int n) {
        long long ans = 0;
        for(long long j = 1, d, x; n > 0; j *= 10) {
            for(long long i = j; i < 10*j && n > 0; i++) {
                x = i;
                d = i/10;
                while(d > 0) {
                    x = 10*x + d%10;
                    d /= 10;
                }
                if(check(x, k)) ans += x, n--;
            }
            for(long long i = j; i < 10*j && n > 0; i++) {
                x = d = i;
                while(d > 0) {
                    x = 10*x + d%10;
                    d /= 10;
                }
                if(check(x, k)) ans += x, n--;
            }
        }
        return ans;
    }
};