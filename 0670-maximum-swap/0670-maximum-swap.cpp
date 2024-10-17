class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        int a = 0, b = 0, mx = n-1;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] < s[mx]) a = i, b = mx;
            if(s[i] > s[mx]) mx = i;
        }
        swap(s[a], s[b]);
        return stoi(s);
    }
};