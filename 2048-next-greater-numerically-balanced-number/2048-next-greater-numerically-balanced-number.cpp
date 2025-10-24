class Solution {
public:
    bool check(int x) {
        vector<int> cnt(10, 0);
        while(x > 0) {
            cnt[x%10]++;
            x /= 10;
        }
        for(int i = 0; i < 10; i++) {
            if(cnt[i] != 0 && cnt[i] != i) return 0;
        }
        return 1;
    }
    int nextBeautifulNumber(int n) {
        n++;
        while(!check(n)) n++;
        return n;
    }
};