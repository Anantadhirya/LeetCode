const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    long long pangkat(long long a, long long b, long long MOD) {
        if(b == 0) return 1;
        return (b&1 ? a : 1) * pangkat(a*a%MOD, b>>1, MOD) % MOD;
    }
    vector<int> sieve(int MX) {
        const int SZ = 1e5 + 5;
        vector<int> primes;
        bitset<SZ> composite;
        for(int i = 2; i <= MX; i++) {
            if(composite[i]) continue;
            primes.push_back(i);
            if(i > MX/i) continue;
            for(int j = i*i; j <= MX; j += i) composite[j] = 1;
        }
        return primes;
    }
    int maximumScore(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> primes = sieve(sqrt(*max_element(nums.begin(), nums.end())) + 5);
        vector<int> ps(n, 0);
        for(int i = 0, tmp; i < n; i++) {
            tmp = nums[i];
            for(int j = 0; primes[j] * primes[j] <= tmp; j++) {
                if(tmp % primes[j] == 0) {
                    ps[i]++;
                    while(tmp % primes[j] == 0) tmp /= primes[j];
                }
            }
            ps[i] += (tmp != 1);
        }
        vector<int> li(n), ri(n);
        vector<pair<int, int>> s;
        s.push_back({INT_MAX, -1});
        for(int i = 0; i < n; i++) {
            while(s.back().first < ps[i]) s.pop_back();
            li[i] = s.back().second + 1;
            s.push_back({ps[i], i});
        }
        s.clear();
        s.push_back({INT_MAX, n});
        for(int i = n-1; i >= 0; i--) {
            while(s.back().first <= ps[i]) s.pop_back();
            ri[i] = s.back().second - 1;
            s.push_back({ps[i], i});
        }
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }
        sort(v.begin(), v.end());
        long long r, p, ans = 1;
        for(int i = n-1, idx, val; i >= 0; i--) {
            val = v[i].first;
            idx = v[i].second;
            r = (long long)(idx - li[idx] + 1)*(ri[idx] - idx + 1);
            p = min((long long)k, r);
            k -= p;
            (ans *= pangkat(val, p, MOD)) %= MOD;
        }
        return ans;
    }
};