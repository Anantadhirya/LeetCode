class Solution {
public:
    string fractionToDecimal(int n, int d) {
        map<int, int> m;
        int idx;
        int neg = (n < 0) ^ (d < 0);
        long long numerator = abs((long long)n);
        long long denominator = abs((long long)d);
        
        string ans = to_string(numerator/denominator);
        string dec;
        numerator %= denominator;

        if(numerator == 0) return (neg && ans != "0" ? "-" : "") + ans;
        while(numerator != 0) {
            if(m.count(numerator)) {
                idx = m[numerator];
                dec = dec.substr(0, idx) + "(" + dec.substr(idx) + ")";
                break;
            } else m[numerator] = dec.size();
            numerator *= 10;
            dec += to_string(numerator / denominator);
            numerator %= denominator;
        }
        return (neg ? "-" : "") + ans + "." + dec;
    }
};