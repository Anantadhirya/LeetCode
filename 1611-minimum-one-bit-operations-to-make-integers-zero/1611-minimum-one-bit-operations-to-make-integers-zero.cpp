class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n <= 1) return n;
        int i = 0;
        while(1<<(i+1) <= n) i++;
        return (1<<(i+1))-1 - minimumOneBitOperations(n - (1<<i));
    }
};