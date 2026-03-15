class Fancy {
public:
    const int MOD = 1e9 + 7;
    vector<int> v;
    int mul = 1, add = 0;
    int pangkat(int a, int b) {
        if(b == 0) return 1;
        return (long long)(b&1 ? a : 1) * pangkat((long long)a*a%MOD, b>>1) % MOD;
    }
    int inv(int x) {
        return pangkat(x, MOD-2);
    }
    Fancy() {
        
    }
    
    void append(int val) {
        val = ((long long)val - add + MOD) % MOD;
        val = (long long)val * inv(mul) % MOD;
        v.push_back(val);
    }
    
    void addAll(int inc) {
        add = ((long long)add + inc) % MOD;
    }
    
    void multAll(int m) {
        mul = ((long long)mul * m) % MOD;
        add = ((long long)add * m) % MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= v.size()) return -1;
        return ((long long)v[idx] * mul % MOD + add) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */