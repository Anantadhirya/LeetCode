class Solution {
public:
    string thousandSeparator(int n) {
        string tmp = to_string(n), ans = "";
        int k = tmp.size();
        for(int i = 0; i < k; i++) {
            ans += tmp[i];
            if((i + 1) % 3 == k % 3 && i != k-1) ans += '.';
        }
        return ans;
    }
};