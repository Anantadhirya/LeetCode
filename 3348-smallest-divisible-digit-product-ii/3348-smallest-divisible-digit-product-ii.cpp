#pragma GCC optimize("Ofast")
auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); };
class Solution {
public:
    vector<int> primes = {2, 3, 5, 7};
    bool valid(vector<int> &req, int cnt0) {
        if(cnt0 > 0) return 0;
        for(int &p: primes) if(req[p] > 0) return 0;
        return 1;
    }
    void f(int x, int add, vector<int> &req) {
        if(x == 2) req[2] += add;
        if(x == 3) req[3] += add;
        if(x == 4) req[2] += 2*add;
        if(x == 5) req[5] += add;
        if(x == 6) req[2] += add, req[3] += add;
        if(x == 7) req[7] += add;
        if(x == 8) req[2] += 3*add;
        if(x == 9) req[3] += 2*add;
    }
    string greedy(vector<int> req, int len) {
        vector<int> cnt(10, 0);
        string ret = "";
        // for(int &p: primes) cout << req[p] << " ";
        // cout << "_ " << len << "\n";
        while(req[2] >= 3) cnt[8]++, req[2] -= 3;
        while(req[3] >= 2) cnt[9]++, req[3] -= 2;
        while(req[2] >= 1 && req[3] >= 1) cnt[6]++, req[2]--, req[3]--;
        while(req[2] >= 2) cnt[4]++, req[2] -= 2;
        for(int &p: primes) if(req[p] >= 0) cnt[p] += req[p];

        if(len != -1) {
            int sm = 0;
            for(int i = 1; i <= 9; i++) sm += cnt[i];
            cnt[1] = len - sm;
            // for(int i = 1; i <= 9; i++) cout << cnt[i] << " \n"[i==9];
            if(sm > len) return "-1";
        }
        for(int i = 1; i <= 9; i++) for(int c = 0; c < cnt[i]; c++) ret.push_back('0'+i);
        // cout << ret << "\n";
        return ret;
    }
    string smallestNumber(string num, long long t) {
        int n = num.size();
        vector<int> req(10, 0);
        int cnt0 = 0;
        for(int &p: primes) {
            while(t % p == 0) t /= p, req[p]++;
        }
        if(t != 1) return "-1";
        for(char &c: num) {
            cnt0 += (c=='0');
            f(c-'0', -1, req);
        }

        // check if equal is valid
        if(valid(req, cnt0)) return num;

        // otherwise, must be greater
        string g;
        for(int i = n-1; i >= 0; i--) {
            f(num[i]-'0', 1, req);
            cnt0 -= (num[i] == '0');
            if(cnt0 != 0) continue;
            for(int x = num[i]-'0'+1; x <= 9; x++) {
                f(x, -1, req);
                g = greedy(req, n-1-i);
                if(g != "-1") {
                    return num.substr(0, i) + char(x+'0') + g;
                }
                f(x, 1, req);
            }
        }
        g = greedy(req, -1);
        if(g.size() <= num.size()) g = string(num.size()-g.size()+1, '1') + g;
        return g;
    }
};