class Solution {
public:
    int splitNum(int x) {
        vector<int> digit;
        int num[2], n;
        while(x) {
            digit.push_back(x%10);
            x /= 10;
        }
        n = digit.size();
        sort(digit.begin(), digit.end());
        num[0] = num[1] = 0;
        for(int i = 0; i < n; i++) {
            num[i&1] = 10*num[i&1] + digit[i];
        }
        return num[0] + num[1];
    }
};