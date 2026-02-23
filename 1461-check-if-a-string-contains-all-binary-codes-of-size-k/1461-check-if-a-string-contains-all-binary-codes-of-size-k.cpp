class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        vector<int> ada(1<<k);
        int cnt = 0;
        for(int i = 0, cur = 0; i < n; i++) {
            cur = 2*cur + (s[i] == '1');
            if(i-k >= 0 && s[i-k] == '1') cur -= (1<<k);
            if(i+1 >= k) {
                if(!ada[cur]) cnt++;
                ada[cur] = 1;
            }
        }
        return cnt == (1<<k);
    }
};