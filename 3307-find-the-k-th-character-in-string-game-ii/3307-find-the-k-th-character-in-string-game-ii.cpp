class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long cnt = 1;
        int i = 0;
        long long shift = 0;
        int n = operations.size();
        while(cnt < k) {
            i++;
            cnt *= 2;
        }
        while(i > 0) {
            cnt /= 2;
            i--;
            if(cnt < k) {
                k -= cnt;
                shift += operations[i];
            }
        }
        return 'a' + (shift % 26);
    }
};