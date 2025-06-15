class Solution {
public:
    int maxDiff(int num) {
        vector<int> v;
        while(num > 0) v.push_back(num%10), num /= 10;
        reverse(v.begin(), v.end());
        int n = v.size();
        int idx1 = 0, idx2 = 0, a = 0, b = 0, to = 0;
        bool sama = 1;
        for(const int &i: v) {
            if(i != v[0]) {
                sama = 0;
                break;
            }
        }
        while(idx1+1 < n && v[idx1] == 9) idx1++;
        while(idx2+1 < n && v[idx2] <= 1) idx2++;
        to = (idx2 == 0 || sama);
        for(const int &i: v) {
            a = 10*a + (i == v[idx1] ? 9 : i);
            b = 10*b + (i == v[idx2] ? to : i);
        }
        return a - b;
    }
};