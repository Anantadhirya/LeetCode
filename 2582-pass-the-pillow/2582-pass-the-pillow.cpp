class Solution {
public:
    int passThePillow(int n, int time) {
        time %= 2*(n-1);
        if(time < n) return 1 + time;
        else return n - (time - (n-1));
    }
};